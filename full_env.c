#include "main.h"

/*
 *env_fun - Function that prints the environment.
 *@line: the line that user enter.
 *we need to free this line after the user use env.
 */

void full_env(char *line)
{
	/*Pointer to the arr of env variables*/
	char **env = environ;
	/*Loop through the array of environment variables*/
	while (*env != NULL)
	{
		/*Print the current environment variable*/
		printf("%s\n", *env);
		env++; /*Move to the next environment variable*/
	}

	/*Free the memory for the input line*/
	free(line);
}
