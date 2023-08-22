#include "main.h"
/**
*read_cmdline - Funtion that read a line of input from the user using getline
 *@path_name: path name.
 *@path_arr: array of paths.
 *Return: line.
 */
char *read_cmdline(void)
{
	size_t len = 0;
	char *line = NULL;
	/*char *new = NULL;
	char *new_line = NULL; */

	if (getline(&line, &len, stdin) == -1)
	{
		/*write(STDOUT_FILENO, "\n", 1); */
		/*If reading fails, free allocated memory and exit*/
		free(line);
		exit(EXIT_SUCCESS);
	}

	/*Remove leading spaces from the input
	for (new = line; *new == ' ' ; new++) 
	; */
	/*Duplicate the modified input to a new string
	new_line = strdup(new); */
	/*Free the original input line
	free(line); */
	/*Return the cleaned input line*/
	return (line);
}
