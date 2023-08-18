#include "main.h"

/**
 *funny_shell - The main funtion for shell.
 *it will execute any command that enter by
 *the user.
 *Return: 0 in success.
 */
int funny_shell(void)
{
	char *line = NULL, *path_name = NULL;
	char **line_arr = NULL, **path_arr = NULL;

	signal(SIGINT, handle_signal);
	path_name = get_env("PATH");
	path_arr = split_path(path_name);
	while (true)
	{
		prompt_cmd();
		read_cmdline(path_name, path_arr, &line);
		if (*line == '\n')
		{
			free(line);
			continue;
		}
		if (strncmp(line, "exit", 4) == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else if (strncmp(line, "env", 3) == 0)
		{
			full_env(line);
		}
		else
		{
			line_arr = line_to_tokens(line);
			checker(line_arr, path_arr);
			free(line);
		}
	}
	return (EXIT_SUCCESS);
}
