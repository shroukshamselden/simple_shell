#include "main.h"

/**
 * print_err - error message is printed.
 * @in_fo: a param and return info struct.
 * @e_str: A spcfid eror type.
 * Return: 0 if no numbers in the string ,
 * -1 on error, other wise coverted number
*/

void print_err(inf_t *in_fo, char *e_str)
{
	_e_puts(in_fo->f_nam);
	_e_puts(": ");
	prin_di(in_fo->count_line, STDERR_FILENO);
	_e_puts(": ");
	_e_puts(in_fo->argv[0]);
	_e_puts(": ");
	_e_puts(e_str);
}
