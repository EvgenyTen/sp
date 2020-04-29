#include <iostream>
#include <windows.h>
using namespace std;

int PID = 0;

int main(int argc, char* argv[])
{
	cout << "Slave starting  :   " << endl;
	cout << "Number of arguments in command line  :   " << argc << endl;
	cout << "List of arguments in command line  :   " << endl;
	for (int i = 0; i < argc; i++) { cout << i << "  " << argv[i] << endl; }
	PID = atoi(argv[1]);
	cout << "***********************" << endl;
	cout << "Received PID  :   " << PID << endl;
	cout << "***********************" << endl;
	cout << "Waiting " << endl;	
	//PROCESS_INFORMATION pis;
	//STARTUPINFO sis;
	//memset(&sis, 0, sizeof(STARTUPINFO));
   // CreateProcess("E:\\sp\\Debug\\sp", NULL, NULL, NULL, FALSE, NORMAL_PRIORITY_CLASS, NULL, NULL, &sis, &pis);
	//cout << "Process number for Waiting   " << pis.hProcess <<endl;
	WaitForSingleObject((HANDLE)PID, INFINITE);
	cout << " Waiting .........  " << endl;
	cout << "Application finished   " << endl;
	cout << "Exiting  " << endl;
	system("pause");
	ExitProcess(0);//return 0;
}