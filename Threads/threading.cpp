#include <iostream>

#include <pthread.h>

using namespace std;

pthread_t thread1, thread2;

void* doThread(void *args)
{
  int *myPtr = (int *)  args; // change "generic" pointer to point to type we intend
  
  for (int i=0; i< (*myPtr) * 100; i++)
    cout << "Thread " << *myPtr << endl;
  return NULL;
}

int main(int argc, char *argv[])
{


  int id1=1;
  int errCode = pthread_create(&thread1, NULL, doThread, (void *) &id1 );

  int id2=2;
  errCode = pthread_create(&thread2, NULL, doThread, (void *) &id2 );

  pthread_join(thread1, NULL);
  cout << "pthread_create gave " << errCode << endl;
  pthread_join(thread2, NULL);
  

  
  return 0;
}


