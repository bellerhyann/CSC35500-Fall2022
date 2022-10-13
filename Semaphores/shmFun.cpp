#include <iostream>
#include <cstdlib>

#include <sys/sem.h>
#include <sys/shm.h>


using namespace std;

#define SEMSET_SIZE 1
#define NUM_OPS 1

int main(int argc, char *argv[])
{
  if (argc != 3)
    {
      cerr << "Usage: " << argv[0] << " <shm key> <sem key>" << endl;
      return 1;
    }

  int myKeyVal = atoi (argv[1]);
  int semKey = atoi(argv[2]);

  int sem_id = semget(semKey, SEMSET_SIZE, 0);
  if (sem_id == -1) // likely semaphore set does not exist ...
    {
      cerr << "Seems to be initial run of code .. creating semaphore ..."
	   << endl;
      // create the semaphore (set)
      sem_id = semget(semKey, SEMSET_SIZE, IPC_CREAT|IPC_EXCL|0600);
      if (sem_id <0)
	{
	  cerr << "semget() failed with errno = ";
	  cerr << errno << endl;
	}
      // initialize the semaphore ...
      semctl(sem_id, 0 /* sem # */,     SETVAL, 1);
    }

  
  
  int shm_id = shmget(myKeyVal, 1024 /* 1KB */, 0);

  if (shm_id==-1)
    {
      /*
      cerr << "shmget() failed with errno = ";
      cerr << errno << endl;
      return 2;
      */
      
      shm_id = shmget(myKeyVal, 1024 /* 1KB */, IPC_CREAT|IPC_EXCL|0600);
 
    }

  int *sharedValuePtr;
  sharedValuePtr = (int *) shmat(shm_id, NULL, 0);

  if (sharedValuePtr == (int *) -1)
    {
      cerr << "shmat() failed" << endl;
      return 3;
    }

  while(true)
    {
      // sem wait
      struct sembuf semWaitCommand[NUM_OPS];
      semWaitCommand[0].sem_num = 0; // do this to the first semaphore in set
      semWaitCommand[0].sem_op = -1; // standard wait (decr and go to queue)
      semWaitCommand[0].sem_flg = 0; // good default flags
      semop(sem_id, semWaitCommand, NUM_OPS); 
      
      sharedValuePtr[0] = 1;
      sharedValuePtr[0] = 3 * sharedValuePtr[0] + 7; // this should be 10. Right?

      if (sharedValuePtr[0] != 10 )
	{
	  cerr << "OH NO ... I got " << sharedValuePtr[0] << endl; 
	}

      
      // sem signal
      struct sembuf semSigCommand[NUM_OPS];
      semSigCommand[0].sem_num = 0; // do this to the first semaphore in set
      semSigCommand[0].sem_op = +1; // standard signal (incr and wake queue)
      semSigCommand[0].sem_flg = 0; // good default flags
      semop(sem_id, semSigCommand, NUM_OPS); 

      



    }
  
  int detatch_status = shmdt(sharedValuePtr);
  if (detatch_status != 0)
    {
      cerr << "shmdt() failed" << endl;
      return 4;
    }
  
  return 0;
}






    
