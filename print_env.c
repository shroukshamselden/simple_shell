#include "main.h"

/**
 * print_env - function to print the environment variables
 * @environ: pointer to the array of environment variables
 * @i: index to start printing from
 */

void print_env(char **environ, int i)
{
	int len = 0;

	while (environ[i])
	{
		while (environ[i][len] != '\0')
		{
			len++;
		}
		write_string(environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
