#include "main.h"
/**
 *_execute - Execute a command.
 *@full: Full path of the command.
 *@line_arr: Array of arguments for the command.
 *Return: Exit status of the executed command.
 */
int _execute(char *full, char **line_arr)
{
	int exec_stat = 0, exit_stat = 0;
	int status;
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
			free(line_arr), free(full);
			/*Indicate command execution failure*/
			exit(EXIT_FAILURE);
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
