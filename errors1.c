#include "shell.h"

/**
 *_eputs - function that prints an input string
 * @string: the string tht is to be printed
 *
 * Return: Nothing
 */
void _eputs(char *string)
{
	int pk = 0;

	if (!string)
		return;
	while (string[pk] != '\0')
	{
		_eputchar(string[pk]);
		pk++;
	}
}

/**
 * _eputchar - function that writes the character d to stderr
 * @d: The char to written
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno  printed.
 */
int _eputchar(char d)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (d == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(2, buf, j);
		j = 0;
	}
	if (d != BUF_FLUSH)
		buf[j++] = d;
	return (1);
}

/**
 * _putfd - function tht writes the char d to  fd
 * @d:  char to be printed
 * @fd:  Filedescriptor to write to or modify
 *
 * Return: on success 1.
 * On error, -1 is returned, and errno is returned.
 */
int _putfd(char d, int fd)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (d == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(fd, buf, j);
		j = 0;
	}
	if (d != BUF_FLUSH)
		buf[j++] = d;
	return (1);
}

/**
 *_putsfd -function tht  prints  input string
 * @string: The string to  print
 * @fd:  Filedescriptor to write or modify
 *
 * Return: The number of chars put
 */
int _putsfd(char *string, int fd)
{
	int pk = 0;

	if (!string)
		return (0);
	while (*string)
	{
		pk += _putfd(*string++, fd);
	}
	return (pk);
}
