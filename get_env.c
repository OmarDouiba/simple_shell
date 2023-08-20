#include "main.h"

/**
 * *get_env - Funtion that return the envirement
 *@str: variable name.
 *Return: The path, otherise NULL.
 */
char *get_env(char *str)
{
	int i = 0, t_or_f = 0;
	char *path_name = NULL;

	/*Loop through each environment variable*/
	for (i = 0; environ[i]; i++)
	{
		t_or_f = true_false(str, i);
		/*If the names match, copy the environment variable's value*/
		if (t_or_f == 0)
		{ /*Copy the environment variable's value*/
			path_name = strdup(environ[i]);
			if (path_name == NULL)
				exit(EXIT_FAILURE);
			/*Return the value*/
			return (path_name);
		}
	}

	/*Return NULL if the environment variable is not found*/
	return (NULL);
}

/**
 *true_false - boolien function
 *@str: string
 *@i: int
 *Return: bool
 */
bool true_false(const char *str, int i)
{
	int j = 0;
	/*Compare the characters until '=' to the provided name*/
	while (environ[i][j] != '=')
	{
		if (environ[i][j] != str[j])
		{
			return (1);
		}
		else
			return (0);
		j++;
	}
}
