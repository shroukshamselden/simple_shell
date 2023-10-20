#include "main.h"

/**
 * print_env - prints the env
 */
void print_env(void)
{
	int i = 0;

	while (environ[i])
	{
		int a = 0;

		while (environ[i][a] != '\0')
		{
			a++;
		}
		write(1, environ[i], a);
		write(1, "\n", 1);
		i++;
	}
}
