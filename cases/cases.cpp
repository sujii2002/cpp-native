#include "header.h"

int main() {

    for (int i = 0; i < 100; i++) {
        char* a = new char[3000];
        const char* b = (strcmp(a, "") == 0) ? "True" : a;
        std::cout << i << " = " << b << "\n";
    }

    char buffer[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(buffer);

    GetOurComputer(buffer,size);

    printf("Computer name: %s\n", buffer);

    char Folder[100];
    GetExePath(buffer, Folder);

    CreateDirectoryA(Folder, NULL);
    char path[100];
    GetExeFullPath(path, Folder, buffer);

    std::cout << processName(path);

    StartApp(processName(path));

    DeleteFileA(path);
    printf("Program may continue. \n", path);

    printf("Deleted successfully the file : %ws.\n", path);

    return 0;
}