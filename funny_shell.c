#include "main.h"

/**
 *funny_shell - The main funtion of the shell.
 *it will execute any command that enter by
 *the user.
 *Return: 0 in success.
 */
void funny_shell(void)
{
	char *line = NULL, **line_arr = NULL;
	int eixt_stat = 0;

	/*Set up signal handler for Ctrl+C (SIGINT)*/
	signal(SIGINT, handle_signal);
	while (true)
	{
		prompt_cmd(); /*Display the command prompt*/
		line = read_cmdline();
		if (strncmp(line, "exit", 4) == 0)
		{ /*Check if the user entered the "exit" command*/
			/*Free allocated memory*/
			free(line), line = NULL;
			exit(eixt_stat); /*Exit, with the recorded exit status*/
		} /*Check if the user entered the "env" command*/
		else if (strncmp(line, "env", 3) == 0)
			full_env(line); /*Display environment variables*/
		else /*Handle other commands*/
		{ /*Tokenize the command line*/
			line_arr = line_to_tokens(line);
			if (line_arr == NULL)
				continue;
			eixt_stat = pathcmd_handler(line_arr);
			/*Free allocated memory*/
			free(line_arr), free(line);
			line = NULL, line_arr = NULL;
		}
	}
}
