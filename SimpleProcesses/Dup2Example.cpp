#include <cstdio>
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
  /*
  for (int index =0; index< argc; index++)
    {
      cout << argv[index] << endl; 
    }
  */

  FILE *fp = fopen(argv[1], "r");
  dup2( fileno(fp), fileno(stdin) );
  
  
  int var;

  cin >> var;

  cout << var * var << endl;

  return 0;
}
