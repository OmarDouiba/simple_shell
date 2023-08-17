#include "main.h"

/**
 *split_path - Funtion that split string into substrings.
 *@p_name: tha path name.
 *Return: The path in 2d array.
 */
char **split_path(char *p_name)
{
	int i = 0, count = 0;
	char *token = NULL;
	char **path_arr = NULL;

	if (p_name != NULL || p_name[i] != '\0')
	{
		while (p_name[i] != '\0')
		{
			if (p_name[i] == ':')
				count++;
			i++;
		}
		count++;
	}
	if (count != 0)
	{
		path_arr = malloc(sizeof(char *) * (count + 1));
		if (path_arr == NULL)
			exit(EXIT_FAILURE);
		token = strtok(p_name, "=");
		token = strtok(NULL, ":\n");
		i = 0;
		while (token != NULL)
		{
			path_arr[i] = token;
			i++;
			token = strtok(NULL, ":\n");
		}
		path_arr[i] = NULL;
	}
	return (path_arr);
}
