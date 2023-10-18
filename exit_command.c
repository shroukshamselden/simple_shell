#include "main.h"

int is_exit_command(char* command)
{
    if (command[0] == 'e' && command[1] == 'x' && command[2] == 'i' && command[3] == 't')
    {
        return 1;
    }
    return 0;
}
