#include "header.h"

void GetExePath(char* buffer,char* Folder) {
    // Constructing a path based on the computer name
    sprintf(Folder, "C:\\Users\\%s\\Desktop\\%s\\NewFolder", buffer, buffer);
}