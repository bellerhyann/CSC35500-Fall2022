#include <cstdlib>
#include <iostream>

#include <sys/sem.h>

using namespace std;

#define NUM_SEMAPHORES 1

int main(int argc, char *argv[])
{
  if (argc!=2)
    {
      cerr << "Usage: " << argv[0] << " <key-value>" << endl;
      return 1;
    }

  int sharedKey = atoi(argv[1]);

  int sem_id = semget(sharedKey, NUM_SEMAPHORES, IPC_CREAT|IPC_EXCL|0600 );

  cout << "semget gave:" << sem_id << endl;
  return 0;
}
