#include "main.h"

/**
 * main - Entry point
 * Return: 0 always success
 */


int main(void)
{
	int s_status;
	pid_t pid;
	char *a_rgv[NUM_ARGS];
	char command[100];
	int i = 0;

	while (1)
	{
		write(1, "> ", 2);
		while
			(read(0, &command[i], 1) != -1 && command[i] != '\n' && i < BUFFER_SIZE - 1)
		{
			write(1, &command[i], 1);
			i++;
		}
		command[i] = '\0';
		i = 0;
		parse_command(command, a_rgv);
		if (is_exit_command(a_rgv[0]))
		{
			exit(0);
		}
		execute_command(a_rgv, &pid, &s_status);
		write(1, "\n", 1);
	}
	return (0);
}
