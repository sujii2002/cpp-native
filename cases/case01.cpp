#include "header.h"

LPSTR processName(const char* name) {
    char buffer[MAX_NAME_LENGTH];
    strcpy(buffer, name); // Potential buffer overflow vulnerability if name is longer than MAX_NAME_LENGTH
    return buffer;
}