#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A simple implementation of encodeShellString
// Escapes special characters for shell commands.
void encodeShellString(char *dest, size_t destSize, const char *src) {
    size_t destIndex = 0;
    for (size_t i = 0; src[i] != '\0' && destIndex < destSize - 1; i++) {
        switch (src[i]) {
            case ' ':
            case '"':
            case '\'':
            case '\\':
            case '&':
            case ';':
            case '|':
            case '<':
            case '>':
            case '`':
            case '$':
                if (destIndex + 2 >= destSize - 1) {
                    break; // Ensure space for the escape and the null terminator
                }
                dest[destIndex++] = '\\';
                dest[destIndex++] = src[i];
                break;
            default:
                dest[destIndex++] = src[i];
                break;
        }
    }
    dest[destIndex] = '\0';
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <unused_arg> <user_name>\n", argv[0]);
        return 1;
    }

    char *userName = argv[2];

    {
        // BAD: a string from the user is injected directly into
        // a command line.
        char command1[1000] = {0};
        sprintf(command1, "userinfo -v \"%s\"", userName);
        printf("Executing (insecure): %s\n", command1);
        system(command1);
    }
    
        // BAD: a string from the user is injected directly into
        // a command line.
        char command2[1000] = {0};
        command2= userName;
        //sprintf(command1, "userinfo -v \"%s\"", userName);
       // printf("Executing (insecure): %s\n", command1);
        system(command2);
    
        // BAD: a string from the user is injected directly into
        // a command line.

        //sprintf(command1, "userinfo -v \"%s\"", userName);
       // printf("Executing (insecure): %s\n", command1);
        char command4[1000]={0};
        strcpy(command4, command2);
        system(command4);
    

    {
        // GOOD: the user string is encoded by a library routine.
        char userNameQuoted[1000] = {0};
        encodeShellString(userNameQuoted, sizeof(userNameQuoted), userName);
        char command2[1000] = {0};
        sprintf(command2, "userinfo -v %s", userNameQuoted);
        printf("Executing (secure): %s\n", command2);
        system(command2);
    }

    return 0;
}

