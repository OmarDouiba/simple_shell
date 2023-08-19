#include "main.h"

/**
 *print_str - Function that print string.
 *Return: string
 */
int print_str(char *str)
{
	/*Use the write system call*/
	/*to print the string to the standard output (stdout)*/
	/*The write function returns the number of characters written*/
	return (write(STDOUT_FILENO, str, strlen(str)));
}
