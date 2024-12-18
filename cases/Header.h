#include<iostream>
#include<windows.h>

LPSTR processName(const char* name);
void GetOurComputer(char* buffer, DWORD size);
void GetExePath(char* buffer, char* Folder);
void GetExeFullPath(char* path, char* Folder, char* buffer);
void StartApp(LPSTR lpApplicationName);

#define MAX_NAME_LENGTH 50
#pragma warning(disable:4996)
