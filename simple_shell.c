#include "main.h"

/**
 * main - entry point
 * Return: 0 alawys success
 */

int main(void)
{
	int s_status;
	pid_t pid;
	char *a_rgv[NUM_ARGS]; /* hold args of comnd included comnd itself*/
	bool pipe = true;
	char *comnd = NULL;
	size_t buff_size = 0;
	int i = 0;

	while (1 && pipe)
	{
		if (isatty(STDIN_FILENO) == 0) /*check if we are using terminal or pipe*/
		{
			pipe = false;
		}
		comnd = read_command(comnd, &buff_size);
		parse_command(comnd, a_rgv);
		if (is_exit_command(a_rgv[0]))
		{
			free(comnd);
			exit(0);
		}
		if (a_rgv[0][0] == 'e' && a_rgv[0][1] == 'n')
		{
			if (a_rgv[0][2] == 'v' && a_rgv[0][3] == '\0')
			{
				while (environ[i])
				{
					print_env(environ, i);
					i++;
				}
			}
			execute_command(a_rgv, &pid, &s_status);
		}
<<<<<<< HEAD
		free(comnd);
	}
		return (0);
=======
		pid = fork(); /*create child process*/
		if (pid == -1)
		{
			perror("Error: fork has failed");
			free(comnd);
			exit(1);
		}
		if (pid == 0)
		{
			val = execve(a_rgv[0], a_rgv, NULL);
			/**val = execvp(a_rgv[0], a_rgv);*/
			if (val == -1)
			{
				perror("./shell");
				free(comnd);
				exit(1);
			}
		}
		if (waitpid(pid, &s_status, 0) == -1)
		{
			perror("Error: waitpid failed");
			free(comnd);
			exit(1);
		}
>>>>>>> 21a6cb96d8e22e0fbc424f9c23c1cd7a420c99dd
	}
