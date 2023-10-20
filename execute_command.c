#include "main.h"

/**
 * execute_command - function to execute the command
 * @a_rgv: pointer to the array of arguments
 * @pid: pointer to the process id
 * @s_status: pointer to the status of the child process
 */

void execute_command(char *a_rgv[NUM_ARGS], pid_t *pid, int *s_status)
{
	int val;

	*pid = fork();
	if (*pid == -1)
	{
		perror("Error: fork has failed");
		free(a_rgv[0]);
		exit(1);
	}
	if (*pid == 0)
	{
		val = execve(a_rgv[0], a_rgv, NULL);
		if (val == -1)
		{
			perror("./shell");
			exit(1);
		}
	}
	if (waitpid(*pid, s_status, 0) == -1)
	{
		perror("Error: waitpid failed");
		exit(1);
	}
}
