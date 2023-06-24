#include "shell.h"

/**
 * _erratoi - function tht converts  string to  integer
 * @str:  string to be converted
 * Return: 0 if no no in string, converted number if worked
 *       -1 on error
 */
int _erratoi(char *str)
{
	int pk = 0;
	unsigned long int result = 0;

	if (*str == '+')
		str++;  /*   does this make main print 255? */
	for (pk = 0;  str[pk] != '\0'; pk++)
	{
		if (str[pk] >= '0' && str[pk] <= '9')
		{
			result *= 10;
			result += (str[pk] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - Function that prints an error message
 * @info:  Parameter info struct
 * @est: String containing  error
 * Return: 0 if no numbers in string, converted number if worked
 *        -1 on error
 */
void print_error(info_t *info, char *est)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(est);
}

/**
 * print_d - Function tht  prints  decimal number (base 10)
 * @inp: Input value
 * @fd: Filedescriptor to write or modify
 *
 * Return: No of char printed
 */
int print_d(int inp, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (inp < 0)
	{
		_abs_ = -inp;
		__putchar('-');
		count++;
	}
	else
		_abs_ = inp;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - function that converts  a no
 * @nm: the number
 * @base:  the base
 * @flag: the argument flags
 *
 * Return: the string
 */
char *convert_number(long int nm, int base, int flag)
{
	static char *arr;
	static char buffer[50];
	char sign = 0;
	char *pt;
	unsigned long m  = nm;

	if (!(flag & CONVERT_UNSIGNED) && nm < 0)
	{
		m = -nm;
		sign = '-';

	}
	arr = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pt = &buffer[49];
	*pt = '\0';

	do	{
		*--pt = arr[m % base];
		m /= base;
	} while (m != 0);

	if (sign)
		*--pt = sign;
	return (pt);
}

/**
 * remove_comments - function that replaces the first instance of '#' with null
 * @buff: Address of the string that will be modified
 *
 * Return: always 0;
 */
void remove_comments(char *buff)
{
	int pk;

	for (pk = 0; buff[pk] != '\0'; pk++)
		if (buff[pk] == '#' && (!pk || buff[pk - 1] == ' '))
		{
			buff[pk] = '\0';
			break;
		}
}
