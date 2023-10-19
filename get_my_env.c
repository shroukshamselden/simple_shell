#include "main.h"


/**
 * _getenv - it can get the val of za environ var.
 *
 * @in_fo : it isa  Structure that contain an args.
 * @nme : var name of env.
 *
 * Return:  value will be returned.
*/
char *_getenv(inf_t *in_fo, const char *nme)
{
	list_t *nde  = in_fo->env;
	char *h;

	while (nde)
	{
		h = strt_wz(nde->strr, nme);
		if (h && *h)
			return (h);
		nde = nde->nxt;
	}
	return (NULL);
}
