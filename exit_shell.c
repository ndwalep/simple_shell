#include "shell.h"

/**
 **_strncpy - Functions that copies a string
 *@desti:  Destination string
 *@srce: source string
 *@m:  no  of characters to be copied
 *Return:  concat string
 */
char *_strncpy(char *desti, char *srce, int m)
{
	int l, k;
	char *s = desti;

	l = 0;
	while (srce[l] != '\0' && l < m - 1)
	{
		desti[l] = srce[l];
		l++;
	}
	if (l < m)
	{
		k = l;
		while (k < m)
		{
			desti[k] = '\0';
			k++;
		}
	}
	return (s);
}

/**
 **_strncat - Function that concatenates two strings
 *@dest: first string
 *@src: second string
 *@m: the no of bytes to be used
 *Return: Concatenated string
 */
char *_strncat(char *dest, char *src, int m)
{
	int l, k;
	char *s = dest;

	l = 0;
	k = 0;
	while (dest[l] != '\0')
		l++;
	while (src[k] != '\0' && k < m)
	{
		dest[l] = src[k];
		l++;
		k++;
	}
	if (k < m)
		dest[l] = '\0';
	return (s);
}

/**
 **_strchr - function that locates a char in a string
 *@str: The string  parsed
 *@d: Char
 *Return: (str)  ptr to  memory area
 */
char *_strchr(char *str, char d)
{
	do {
		if (*str == d)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
