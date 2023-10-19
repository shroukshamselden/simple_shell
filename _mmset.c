
#include "main.h"

/**
 * _mmset - it  fls memry bu a cnstnt byt.
 *
 * @m : pointer to the area of memory..
 * @p : byt to fil *m .
 * @b : amount of byts.
 *
 * Return: a pointer that is called m
*/


char *_mmset(char *m, char p, unsigned int b)
{
	unsigned int k;

	for (k = 0; k < b; k++)
		m[k] = p;
	return (m);
}
/**
 * ad_nde - it add  node at the end of the lst.
 *
 * @hed : addrs of pointr to head node.
 * @str : str field of node
 * @nm : node index used by history
 *
 * Return: size of list
*/

list_t *ad_nde(list_t **hed, const char *str, int nm)
{
	list_t *nw_nde, *nde;

	if (!hed)
		return (NULL);

	nde = *hed;
	nw_nde = malloc(sizeof(list_t));
	if (!nw_nde)
		return (NULL);
	_mmset((void *)nw_nde, 0, sizeof(list_t));
	nw_nde->number = nm;
	if (str)
	{
		nw_nde->strr = _str_dup(str);
		if (!nw_nde->strr)
		{
			free(nw_nde);
			return (NULL);
		}
	}
	if (nde)
	{
		while (nde->nxt)
			nde = nde->nxt;
		nde->nxt = nw_nde;
	}
	else
		*hed = nw_nde;
	return (nw_nde);
}

