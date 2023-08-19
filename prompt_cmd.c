#include "main.h"

/**
 *prompt_cmd - Function that display a prompt "$ " to the user.
 */
void prompt_cmd(void)
{
	if (isatty(STDIN_FILENO))
	{
		/*Flush any buffered input from the standard input*/
		fflush(stdin);
		/*Write the prompt "$ " to the standard output*/
		write(STDOUT_FILENO, "$ ", 2);
	}
}
