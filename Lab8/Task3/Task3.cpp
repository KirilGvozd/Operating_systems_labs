#include <iostream>
#include <Windows.h>
using namespace std;
#define KB (1024)
#define MB (1024 * KB)
#define PG (4 * KB)


int main()
{
    int pages = 256;
    int countItems = pages * PG / sizeof(int);

    LPVOID xmemaddr = VirtualAlloc(NULL, pages * PG, MEM_COMMIT, PAGE_READWRITE);
    cout << "Allocated " << pages * PG / 1024 << " KB of virtual memory." << endl;

    int* arr = (int*)xmemaddr;
    for (int i = 0; i < countItems; i++) {
        arr[i] = i;
    }
    /* Г = С3
       в = E2
       о = EE

       Страница С3 = 195, смещение E2E = 3630

       Значение в байте должно получится 195 * 1024 + 3630 = 203310
    */

    int* byte = arr + 195 * KB + 3630;
    cout << "Value of memory in byte: " << *byte << endl;


    if (!VirtualFree(xmemaddr, NULL, MEM_RELEASE))
        cout << "Error in releasing allocated memory." << endl;

    return 0;
}