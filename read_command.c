#include "main.h"

/**
 * *read_command - function to read command
 * @comnd: command to read
 * @buff_size: size
 * Return: comnd
 */
char *read_command(char *comnd, size_t *buff_size)
{
	ssize_t letrs;
	char *prompt = "cisfun$ ";

	write(1, prompt, 8);
	fflush(stdout);
	letrs = getline(&comnd, buff_size, stdin);
	if (letrs == -1)
	{
		free(comnd);
		exit(1);
	}
	if (comnd[letrs - 1] == '\n')
	{
		comnd[letrs - 1] = '\0';
	}
	return (comnd);
}
