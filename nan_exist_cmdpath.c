#include "main.h"

/**
 *nan_exist_cmd - Function to handle non-existent
 *command execution using provided paths
 *@path_arr: array of strings.
 *@line_arr: array of strings
 *Return: Exit stat.
 */

int nan_exist_cmd(char **path_arr, char **line_arr)
{
	char *full = NULL;
	int exit_stat = 127;
/*Check if path_arr or line_arr is NULL or line_arr's first element is NULL*/
	if (path_arr == NULL || line_arr == NULL || line_arr[0] == NULL)
	{
		/*Free the memory allocated for line_arr*/
		free(line_arr);
		/*free(path_arr)*//*add*/
		/*Exit with failure status*/
		exit(EXIT_FAILURE);
	}

	/*Create a full path*/
	full = concat_line_path(line_arr[0], path_arr);
	if (full != NULL)
	{
		/*Execute the command with arguments*/
		exit_stat = _execute(full, line_arr);
		/*Free the memory allocated for full path*/
		free(full);
		/*Free the memory allocated for line_arr*/
		free(line_arr);
	}
	return (exit_stat);
}
