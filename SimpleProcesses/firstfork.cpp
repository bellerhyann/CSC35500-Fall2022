#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
	cout << "parent pid = " << getpid() << endl; 
	
	//srand(time(NULL));
	//int pid = rand()%2;
	int pid = fork();	

	cout << "single line of output" << endl;	
	/*
	if (pid!=0)
		cout << "In parent, pid = " << pid << endl;
	else
		cout << "In child, pid = " << pid << endl;
	*/
	
	
	return 0;
}
