#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    LPCWSTR path1 = L"C:\\Labs\\Operating_systems\\Lab3\\os03_02_1\\x64\\Debug\\os03_02_1.exe";
    LPCWSTR path2 = L"C:\\Labs\\Operating_systems\\Lab3\\os03_02_2\\x64\\Debug\\os03_02_2.exe";

    STARTUPINFO si;
    PROCESS_INFORMATION pi1;
    PROCESS_INFORMATION pi2;

    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    if (CreateProcess(path1, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi1))
    {
        std::cout << "Child process OS_02_1 is created." << endl;
    }
    else {
        std::cout << "Child process OS_02_1 is not created." << endl;
    }

    if (CreateProcess(path2, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi2))
    {
        std::cout << "Child process OS_02_2 is created." << endl;
    }
    else {
        std::cout << "Child process OS_02_2 is not created." << endl;
    }

    for (int i = 0; i < 100; i++) {
        cout << "PID: " << GetCurrentProcessId() << endl;
        Sleep(1000);
    }

    WaitForSingleObject(pi1.hProcess, INFINITE);
    WaitForSingleObject(pi2.hProcess, INFINITE);
    CloseHandle(pi1.hProcess);
    CloseHandle(pi2.hProcess);
}