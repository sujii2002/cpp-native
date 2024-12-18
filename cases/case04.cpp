#include "header.h"

void GetExeFullPath(char* path, char* Folder,char* buffer) {
    // Potential vulnerability if buffer contains format specifiers
    sprintf(path, "%s\\test.exe", Folder, buffer);
}