#include "main.h"
#include <unistd.h>
/**
 * write_string - function to write the string
 * @str : first param
 * @len : calculate the length of the string
 * Return: no return value
 */
void write_string(char *str, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		write(STDOUT_FILENO, &str[i], 1);
	}
}
