#include <iostream>

#include <pthread.h>
#include <unistd.h>

using namespace std;

pthread_t threadData[8];

void* doThread(void *args)
{
  int *myPtr = (int *)  args; // change "generic" pointer to point to type we intend
  int myVal = *myPtr;
  
  cout << "Take 1: I am thread #" << myVal << " and I think my data ptr is " << *myPtr << endl;

  //sleep(2);

  cout << "Take 2: I am thread #" << myVal << " and I think my data ptr is " << *myPtr << endl;

  return NULL;
}

int main(int argc, char *argv[])
{
  int id1;

  for (id1=1; id1<=8; id1++)
    {
      int *data = new int(id1);
      pthread_create(&threadData[id1-1], NULL, doThread, (void *) data );
    }

  for (int tNum=0; tNum<8; tNum++)
    pthread_join(threadData[tNum], NULL);

  cout << "Main finishes !!!" << endl;

  
  return 0;
}


