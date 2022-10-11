#include <cstdlib>
#include <iostream>

#include <sys/sem.h>

using namespace std;

#define NUM_SEMAPHORES 1
#define NUM_COMMANDS 1

int main(int argc, char *argv[])
{
  if (argc!=2)
    {
      cerr << "Usage: " << argv[0] << " <key-value>" << endl;
      return 1;
    }

  int sharedKey = atoi(argv[1]);

  int sem_id = semget(sharedKey, NUM_SEMAPHORES, 0 );

  if (sem_id <0 )
    {
      cerr << "semget() call failed! " << endl;
      return 2;
    }

  struct sembuf semWaitCommand[NUM_COMMANDS];

  semWaitCommand[0].sem_num =0;
  semWaitCommand[0].sem_op  =-1;
  semWaitCommand[0].sem_flg =0;

  int result = semop(sem_id, semWaitCommand, NUM_COMMANDS);

  if (result == -1)
    {
      cerr << "semop()  /* wait */ failed. " << endl;
      return 3;
    }

  cout << "done waiting!" << endl;
  
  return 0;
}
