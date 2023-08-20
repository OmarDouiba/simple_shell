#include "shell.h"
/**
 * execmd - fuction that handling the command execution
 *
 * @**argv: is an array of strings,where each string represents
 * an argument for the command that needs to be executed
 *
 * Return: void
 */

void execmd(char **argv)
{
	char *command = NULL, *new_command = NULL;

	if (argv)
	{
		command = argv[0];
		new_command = get_location(command);

		if (execve(new_command, argv, NULL) == -1)
		{
			perror("Error");
		}
	}
}
