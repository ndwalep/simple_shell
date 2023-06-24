#include "shell.h"

/**
 * _strlen - Function that prints length of a string
 * @r:  String whose length to be printed
 *
 * Return: int length of string
 */
int _strlen(char *r)
{
	int pk = 0;

	if (!r)
		return (0);

	while (*r++)
		pk++;
	return (pk);
}
/**
 * starts_with - function that checks whether  needle begins with haystack
 * @haystack: String to be searched for
 * @needle: The substring to be sought
 *
 * Return: Address of next character of haystack or NULL if otherwise
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}
/**
 * _strcat - Function that concatenates desti and srce
 * @desti: Destination buffer
 * @srce:  Source buffer
 *
 * Return: ptr to desti buffer
 */
char *_strcat(char *desti, char *srce)
{
	char *p = desti;

	while (*desti)
		desti++;
	while (*srce)
		*desti++ = *srce++;
	*desti = *srce;
	return (p);
}
/**
 * _strcmp -  function that compares of two strangs.
 * @str1:  First string
 * @str2:  Second string
 *
 * Return: Negative if str1 < str2,
 *	Positive if str1 > str2,
 *	zero if str1 == str2
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}
