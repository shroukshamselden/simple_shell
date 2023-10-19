#include "main.h"

/**
 * _e_putchar - char to the stderr
 * @ch : char to be printed
 * Return: On success 1. -1 is returned on errno ,
 * and errnois set appropriately.
*/
int _e_putchar(char ch)
{
	static int k;
	static char buff[WRTE_BFF_SZE];

	if (ch == BUFF_FLSH || k >= WRTE_BFF_SZE)
	{
		write(2, buff, k);
		k = 0;
	}
	if (ch != BUFF_FLSH)
		buff[k++] = ch;
	return (1);
}
/**
 * prin_di - func prints an ( dec / integer) num.
 *
 * @inpt : AN input.
 * @fdd : f\ile descriptor..
 *
 * Return: number of characters printed
*/
int prin_di(int inpt, int fdd)
{
	int (*__putchar)(char) = _putchar;
	int k, cnt = 0;
       	unsigned int _ab_, curnt; /** cnt = count*/

	if (fdd == STDERR_FILENO)
		__putchar = _e_putchar;
	if (inpt < 0)
	{
		_ab_ = inpt;
		__putchar('-');
		cnt++;
	}
	else
		_ab_ = inpt;
	curnt = _ab_;
	for (k = 1000000000; k > 1; k /= 10)
	{
		if (_ab_ / k)
		{
			__putchar('0' + curnt / k);
			cnt++;
		}
		curnt %= k;
	}
	__putchar('0' + curnt);
	cnt++;
	return (cnt);
}
/**
 * _e_puts - print string as an input
 * @string : string to be printed
 * Return: No return value
*/
void _e_puts(char *string)
{
	int k = 0;

	if (!string)
		return;
	while (string[k] != '\0')
	{
		_e_putchar(string[k]);
		k++;
	}
}

