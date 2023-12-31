#include <iostream>
#include <Windows.h>

using namespace std;
DWORD pid = NULL;

DWORD WINAPI Thread1()
{
	DWORD tid = GetCurrentThreadId();

	for (short i = 0; i < 50; i++)
	{
		if (i == 25)
		{
			Sleep(10000);
		}


		cout << " PID = " << pid << ", Thread1 ID = " << tid << endl;
		Sleep(1000);
	}
	return 0;
}


DWORD WINAPI Thread2()
{
	DWORD tid = GetCurrentThreadId();

	for (short i = 0; i < 125; i++)
	{
		if (i == 80)
		{
			Sleep(15000);
		}

		cout << " PID = " << pid << ", Thread2 ID = " << tid << endl;
		Sleep(1000);
	}
	return 0;
}

int main() {
	pid = GetCurrentProcessId();
	DWORD parentId = GetCurrentThreadId();
	DWORD childId_T1 = NULL;
	DWORD childId_T2 = NULL;
	HANDLE handleClild_T1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread1, NULL, 0, &childId_T1);
	HANDLE handleClild_T2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread2, NULL, 0, &childId_T2);

	for (short i = 0; i < 100; ++i)
	{
		if (i == 30)
		{
			Sleep(10000);
		}

		cout << "\n" << i << " PID = " << pid << ", Thread main ID = " << parentId << endl;
		Sleep(1000);
	}


	WaitForSingleObject(handleClild_T1, INFINITE);
	WaitForSingleObject(handleClild_T2, INFINITE);
	CloseHandle(handleClild_T1);
	CloseHandle(handleClild_T2);
	system("pause");
	return 0;
}