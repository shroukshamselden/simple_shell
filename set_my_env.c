#include "main.h"

/**
  * _set_env - Initialize a new environment variable.
  * @in_fo: Structure containing potential arguments.
  * @var : str env var propert.
  * @val : str env var val.
  * Return: Always 0.
*/

int _set_env(inf_t *in_fo, char *vr, char *val)
{
	char *bf = NULL;
	list_t *nde;
	char *h;

	if (!vr || !val)
		return (0);

	bf = malloc(_strlen(vr) + _strlen(val) + 2);
	if (!bf)
		return (1);
	_strcpy(bf, vr);
	_strcat(bf, "=");
	_strcat(bf, val);
	nde = in_fo->env;
	while (nde)
	{
		h = strt_wz(nde->strr, vr);
		if (h && *h == '=')
		{
			free(nde->strr);
			nde->strr = bf;
			in_fo->changed_env = 1;
			return (0);
		}
		nde = nde->nxt;
	}
	ad_nde(&(in_fo->env), bf, 0);
	free(bf);
	in_fo->changed_env = 1;
	return (0);
}
