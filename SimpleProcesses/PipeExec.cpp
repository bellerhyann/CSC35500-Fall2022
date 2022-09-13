#include <cstdio>
#include <iostream>
#include <unistd.h>

using namespace std;

int main (int argc, char *argv[])
{
  int pipeInfo[2];


  
  int myPipe = pipe(pipeInfo);
  if (myPipe != 0)
    {
      cout << "Could not create pipe ... (!?!?!?!) " << endl;
      return 1;
    }

  int pid = fork();

  if (pid!=0)
    {
      close(pipeInfo[1]);
      dup2(pipeInfo[0], fileno(stdin));
      char *args[2];
      args[0] = "wc";
      args[1] = NULL;
      execvp(args[0], args);
    }
  else  /// do "ls -l"
    {
      close(pipeInfo[0]);
      dup2(pipeInfo[1], fileno(stdout));
      char *args[3];
      args[0] = "ls";
      args[1] = "-l";
      args[2] = NULL;
      execvp(args[0], args);
    }

  return 0;
}
