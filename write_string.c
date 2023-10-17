#include "main.h"
#include <unistd.h>

void write_string(char *str, int len)
{
	int i;
    for (i = 0; i < len; i++) 
    {
        write(STDOUT_FILENO, &str[i], 1);
    }
}
