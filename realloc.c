#include "shell.h"

/**
 **_memset - function that fills memory with a constant byte
 *@s: pointer to the memory area
 *@b: Byte to fill *s (pointer) with
 *@n: Amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int t;

	for (t = 0; t < n; t++)
		s[t] = b;
	return (s);
}

/**
 * ffree - function that frees a string of strings
 * @pp: String of strings to be freed
 *
 * Return: Nothing
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - Function that reallocates a block of memory
 * @ptr: pointer to previous memory block malloced
 * @old_size: Previous block size
 * @new_size: New block size
 *
 * Return: Pointer to de allocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
