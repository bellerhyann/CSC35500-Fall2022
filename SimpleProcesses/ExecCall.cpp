#include <cstring>
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char * argv[])
{
	char* array[3];
	array[0] = new char[10]; strcpy(array[0], "nosuchCommand");
	array[1] = new char[10]; strcpy(array[1], "-a");
	array[2] = NULL;
	
	execvp(array[0], array);
	
	cout << "If we get here, something went wrong!" << endl;	
	
	return 0;
}
