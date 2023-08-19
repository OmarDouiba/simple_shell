#include "main.h"

/**
 *funny_shell - The main funtion of the shell.
 *it will execute any command that enter by
 *the user.
 *Return: 0 in success.
 */
void funny_shell(void)
{
	char *line = NULL, *path_name = NULL;
	char **line_arr = NULL, **path_arr = NULL;
	int eixt_stat = 0;

	/*Set up signal handler for Ctrl+C (SIGINT)*/
	signal(SIGINT, handle_signal);
	/*Get the value of the "PATH" environment variable*/
	path_name = get_env("PATH");
	/*Split the "PATH" into an array of directories*/
	path_arr = split_path(path_name);
	while (true)
	{
		prompt_cmd(); /*Display the command prompt*/
		line = read_cmdline(path_name, path_arr);
		if (*line == '\n') /*If empty, skip the continue*/
		{
			free(line);
			continue;
		}
		if (strncmp(line, "exit", 4) == 0)
		{ /*Check if the user entered the "exit" command*/
			free(line); /*Free allocated memory*/
			free(path_name);
			free(path_arr);
			exit(eixt_stat); /*Exit,with the recorded exit status*/
		} /*Check if the user entered the "env" command*/
		else if (strncmp(line, "env", 3) == 0)
		{ /*Display environment variables*/
			full_env(line);
		} /*Handle other commands*/
		else
		{ /*Tokenize the command line*/
			line_arr = line_to_tokens(line);
			eixt_stat = checker(line_arr, path_arr);
			free(line); /*Free allocated memory */
		}
	}
}
