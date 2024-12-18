#include <cstdlib>
#include <cstdio>

int main()
{
    char *command = getenv("HOME");
    system(command);
}