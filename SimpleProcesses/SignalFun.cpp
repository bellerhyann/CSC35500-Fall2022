#include <iostream>
#include <signal.h>
#include <unistd.h>

using namespace std;

void myHandler(int sNum)
{
  cout << "called myHandler with signal =" << sNum << endl;
}

int main(int argc, char *argv[])
{
  int pid = fork();

  if (pid!=0) // parent
    {
      signal(SIGCHLD, myHandler);
      
      cout << "enter an integer: ";
      int number;
      cin >> number;
      cout << number << "is a good number!" << endl;
    }
  else
    {
      cout << "child going to sleep ...";
      cout.flush();
      sleep(10);
      cout << "child woke up" << endl;
    }
  
  return 0;
}
