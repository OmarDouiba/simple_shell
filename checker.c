#include "main.h"

/**
 *checker - Function checks the command-line input and
 * takes actions accordingly.
 *@line_arr: array of command line.
 *@path_arr: array of path.
 * Return: Exit.
 */
int checker(char **line_arr, char **path_arr)
{
	int exit_stat = 0;
	/*bool t_or_f;*/

	/*Call the true_false2 function to determine*/
	/*if a forward slash is present.*/
	/*t_or_f = true_false2(line_arr);*/
	/*Check the value returned by true_false2 function.*/
	if (true_false2(line_arr) == 1)
/*f a forward slash is present, call pathcmd_handler and reset t_or_f.*/
		exit_stat = pathcmd_handler(line_arr);
	else
		/*If no forward slash is present, call nan_excist_cmd.*/
		exit_stat = nan_exist_cmd(path_arr, line_arr);
	return (exit_stat);
}

/**
 *true_false2 - Function checks if a forward slash is present
 * in the input string.
 * @line_arr: array of command line.
 *Return: bool.
 */
bool true_false2(char **line_arr)
{
	int i = 0;

	/*Loop through the characters of the first string in line_arr.*/
	for (i; line_arr[0][i]; i++)
	{
		if (line_arr[0][i] == '/')
		/*If a forward slash is found, return true (1).*/
			return (1);
	}
	/*If no forward slash is found, return false (0).*/
	return (0);
}
