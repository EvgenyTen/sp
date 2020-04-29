#include <iostream>
#include <windows.h>
using namespace std;

int sleepTime = 0;
PROCESS_INFORMATION pim;
STARTUPINFO sim;

int main(int argc, char* argv[])
{
cout << "Master starting  !!  " << endl;
cout << "Number of arguments in command line  :   " << argc << endl;
cout << "List of arguments in command line  :   "  << endl;
for (int i = 0; i < argc; i++) { cout << i << "  " << argv[i] << endl; }
sleepTime = atoi(argv[1]);
cout << "Received sleepingTime  :   " <<sleepTime<<endl;
memset(&sim, 0, sizeof(STARTUPINFO));
cout << "Going to open application    " << endl;
if (CreateProcess(NULL,(LPTSTR)"E:\\sp\\Debug\\slave.exe",NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &sim, &pim))
{
    cout << "Master PID number  : " << pim.dwProcessId << endl;
    cout << "Master theread number  : " << pim.hProcess << endl;
    CloseHandle(pim.hProcess);
    CloseHandle(pim.hThread);
}else { cout << "Master error " << endl; }
cout << "Going to Sleep  !!!!!!!!     " << endl;
Sleep(sleepTime);

system("pause");
return 0;
}

