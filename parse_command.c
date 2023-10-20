#include "main.h"

/**
 * parse_command - function to parse the command
 * @comnd: pointer to the command string
 * @a_rgv: pointer to the array of arguments
 */

void parse_command(char *comnd, char *a_rgv[NUM_ARGS])
{
	int a_rgc = 0;
	char *token_start = comnd;

	while (a_rgc < NUM_ARGS - 1 && *token_start != '\0')
	{
		while (*token_start == ' ' && *token_start != '\0')
		{
			token_start++;
		}
		a_rgv[a_rgc] = token_start;
		while (*token_start != ' ' && *token_start != '\0')
		{
			token_start++;
		}
		if (*token_start != '\0')
		{
			*token_start = '\0';
			token_start++;
		}
		a_rgc++;
	}
	a_rgv[a_rgc] = NULL;
}
