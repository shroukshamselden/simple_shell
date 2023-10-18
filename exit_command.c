#include "main.h"
/**
 * is_exit_command - function for exit command
 * @command  : my param to check exit
 * Return: 1 if it is exits, and otherwise 0
 */
int is_exit_command(char *command)
{
	if (command[0] == 'e' && command[1] == 'x')
	{
		if (command[2] == 'i' && command[3] == 't')
		{
		return (1);
		}
	}
	return (0);
}
