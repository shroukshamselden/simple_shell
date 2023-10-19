#include "main.h"

/**
 * parse_command - function to parse the command
 * @comnd: pointer to the command string
 * @a_rgv: pointer to the array of arguments
 */
void parse_command(char *comnd, char *a_rgv[NUM_ARGS])
{
	int a_rgc = 0;

	a_rgv[a_rgc] = strtok(comnd, " ");
	while (a_rgc < NUM_ARGS - 1 && a_rgv[a_rgc] != NULL)
	{
		a_rgc++;
		a_rgv[a_rgc] = strtok(NULL, " ");
	}
	a_rgv[a_rgc] = NULL;
}
