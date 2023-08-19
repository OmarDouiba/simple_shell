#include "main.h"
/*
* _execute -
* @full:
* @line_arr:
* Return: Exit.
*/
int _execute(char *full, char **line_arr)
{
	int exec_stat = 0, exit_stat = 0, status;
	pid_t pid;

	/*Create a child process using fork*/
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE); /*Handle fork failure*/

	if (pid == 0) /*Child process*/
	{
		/*Execute the command using execve*/
		exec_stat = execve(full, line_arr, environ);
		if (exec_stat == -1)
		{
			perror(line_arr[0]); /*Print an error message*/
			/*Indicate command execution failure*/
			exit(127);
		}
	}
	else /*Parent process*/
		/*Wait for the child process to finish*/
		wait(&status);
	if (WIFEXITED(status))
		exit_stat = WEXITSTATUS(status);
	/*Indicate successful command execution*/
	return (exit_stat);
}
