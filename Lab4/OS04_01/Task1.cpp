#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
	DWORD pid = GetCurrentProcessId();
	DWORD thid = GetCurrentThreadId();


	for (int i = 0; i < 1000; i++) {
		cout << "\nPID: " << pid;
		cout << "\nTHID: " << thid;
		Sleep(1000);
	}
}