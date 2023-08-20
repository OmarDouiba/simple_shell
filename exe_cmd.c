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
	pid_t pid, wpid;
	int status;

	if (argv)
	{
		command = argv[0];
		new_command = get_location(command);

		if (actual_command)
		{
			pid = fork();
			if (pid == 0)
			{
				if (execve(actual_command, argv, NULL) == -1)
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
					wpid = waitpid(pid, &status, WUNTRACED);
				} while (!WIFEXITED(status) && !WIFSIGNALED(status));
			}
		}
		else
		{
			printf("Command not found: %s\n", command);
		}
	}
}
