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
	char cmnd[100];
	int i = 0;

	while (1)
	{
		write(1, "$ ", 2);
		while
			(read(0, &cmnd[i], 1) != -1 && cmnd[i] != '\n' && i < BUFFER_SIZE - 1)
		{
			write(1, &cmnd[i], 1);
			i++;
		}
		cmnd[i] = '\0';
		i = 0;
		parse_command(cmnd, a_rgv);
		if (is_exit_command(a_rgv[0]))
		{
			exit(0);
		}
		else if
			(cmnd[0] == 'e' && cmnd[1] == 'n' && cmnd[2] == 'v' && cmnd[3] == '\0')
			{
				print_env();
			}
		else
		{
			execute_command(a_rgv, &pid, &s_status);
		}
		write(1, "\n", 0);
	}
	return (0);
}
