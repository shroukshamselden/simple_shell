#include "main.h"

/**
 * _putchar - ch char to the stdout
 * @ch : char to be printed.
 * Return: On success 1.
 * and errno is set appropriate, and -1 on errno.
*/
int _putchar(char ch)
{
	static int k;
       	static char buff[WRTE_BFF_SZE];

	if (ch == BUFF_FLSH || k >= WRTE_BFF_SZE)
	{
		write(1, buff, k);
		k = 0;
	}
	if (ch != BUFF_FLSH)
		buff[k++] = ch;
	return (1);
}

/**
 * _strcmp - prfrm a cmparsion between  2 strs.
 * @str1 : 1st strng.
 * @str2 : 2st strng.
 * Return: 0 if 1str == 2str,  positive if s1 > s2, otherwise neg.
*/

int _strcmp(char * str1, char * str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
	{
		return (0);
	}
	else
	{
		return (*str1 < *str2 ? -1 : 1);
	}
}

/**
 * _puts - prnts string as an input.
 * @string : str to be printd.
 * Return: No return value.
*/

void _puts(char *string)
{
	int k = 0;

	if (!string)
		return;
	while (string[k] != '\0')
	{
		_putchar(string[k]);
		k++;
	}
}
