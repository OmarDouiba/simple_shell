#include "main.h"

/**
 *pathcmd_handler - Function to handle path-based command execution
 *@line_arr: array of strings.
 *Return: the exit status (failure).
 */
int pathcmd_handler(char **line_arr)
{
	struct stat st;
	int exit_stat = 127;

	/*Check if line_arr is NULL or the first element is NULL*/
	if (line_arr == NULL || line_arr[0] == NULL)
	{
		/*Exit with failure status*/
		exit(EXIT_FAILURE);
	}
	/*Check if the specified path exists using stat*/
	if (stat(line_arr[0], &st) == 0)
	{
		/*Execute the command with arguments*/
		exit_stat = _execute(line_arr[0], line_arr);
	}
	else
	{
		/*exit_stat = 127; */
		/*Print the command name*/
		print_str(line_arr[0]);
		/*Print "not found" message*/
		print_str(": not found\n");
	}
	/*Free the memory allocated for line_arr*/
	free(line_arr);
	return (exit_stat);
}
