#include "shell.h"
/**
* bfree - Function that free pointer
* and NULLs the address
* @ptr: Address of the pointer to free
*
* Return: 1 if freed,
* otherwise return 0.
*/
int bfree(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
