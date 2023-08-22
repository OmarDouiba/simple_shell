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
	pid_t pid;
	int status;

	if (argv)
	{
		command = argv[0];
		new_command = get_location(command);

		if (new_command)
		{
			pid = fork();
			if (pid == 0)
			{
				if (execve(new_command, argv, NULL) == -1)
				{
					perror("Error");
					exit(EXIT_FAILURE);
				}
			}
			else if (pid < 0)
			{
				perror("fork error");
			}
			else
			{
				do {
					waitpid(pid, &status, WUNTRACED);
				} while (!WIFEXITED(status) && !WIFSIGNALED(status));
			}
		}
		else
		{
			printf("Command not found: %s\n", command);
		}
	}
}
