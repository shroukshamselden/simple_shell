#include "main.h"

/**
 * _str_dup - it dplicts a str.
 * *@strng : the strng to dplict
 * Return: pontr to zaa dplcatd str.
*/
char *_str_dup(const char *strng)
{
	int lngth = 0;
       	char *rt;

	if (strng == NULL)
		return (NULL);
	while (*strng++)
		lngth++;

	rt = malloc(sizeof(char) * (lngth + 1));
	if (!rt)
		return (NULL);
	for (lngth++; lngth--;)
		rt[lngth] = *--strng;
	return (rt);
}
/**
 * _strcpy - copy the str.
 * @dst_buf : za dstntionn.
 * @source : it is the src.
 * Return: pointer to dst_buf.
*/
char *_strcpy(char *dst_buf, char *source)
{
	int k = 0;

	if (dst_buf == source || source == 0)
		return  (dst_buf);
	while (source[k])
	{
		dst_buf[k] = source[k];
		k++;
	}

	dst_buf[k] = 0;

	return (dst_buf);
}
/**
 * _strcat - cnctnts 2 strs.
 * @dst_buf : the destination of the  bufff.
 * @source : the src buf.
 * Return: pointr to dst_buf.r
 */
char *_strcat(char *dst_buf, char *source)
{
	char *rt = dst_buf;

	while (*dst_buf)
		dst_buf++;
	while (*source)
		*dst_buf++ = *source++;
	*dst_buf = *source;
	return (rt);
}
/**
 * _strlen - returns the length of str.
 * @str : the string => length to chek.
 * Return: intgr lnth of string.
*/
int _strlen(char *str)
{
	int k = 0;

	if (!str)
		return (0);
	while (*str++)
		k++;
	return (k);
}
/**
 * strt_wz - checks if substring starts with string.
 * @string: string to search.
 * @substrng: thr substrng to find.
 * Return: address of next char or NULL.
*/
char *strt_wz(const char *string, const char *substrng)
{
	while (*substrng)
		if (*substrng++ != *string++)
			return (NULL);
	return ((char *)string);
}
