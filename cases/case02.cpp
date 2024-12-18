#include "header.h"

void GetOurComputer(char* buffer,DWORD size) {
    if (!GetComputerNameA(buffer, &size)) {
        printf("Error getting computer name: %d\n", GetLastError());
    }
}