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
  signal(SIGSEGV, myHandler);

  int *ptr = NULL;

  *ptr=8;

  return 0;
}
