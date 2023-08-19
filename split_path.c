#include "main.h"

/**
 *split_path - Function to split a string
 *containing paths into an array of path strings
 *@p_name: tha path name.
 *Return: dynamically allocated array of path strings.
 */
char **split_path(char *p_name)
{
	int i = 0, count = 0;
	char *token = NULL, **path_arr = NULL;

	if (p_name != NULL)
	{
		/*Count the number of path separators */
		/*(':' character) to determine array size*/
		while (p_name[i] != '\0')
		{
			if (p_name[i] == ':')
				count++;
			i++;
		}
		count++;
		if (count != 0)
		{ /*Allocate memory for the array of path strings*/
			path_arr = malloc(sizeof(char *) * (count + 1));
			if (path_arr == NULL)
			{
				free(path_arr);
				/*Handle memory allocation failure*/
				exit(EXIT_FAILURE);
			}
		/*Tokenize the input string using '=' and ':' as delimiters*/
			token = strtok(p_name, "=");
			token = strtok(NULL, ":\n");
			i = 0;
			/*Populate the path array with tokens*/
			while (token != NULL)
			{
				path_arr[i] = token;
				i++;
				token = strtok(NULL, ":\n");
			}
			path_arr[i] = NULL;
		}
		/*Return the dynamically allocated array of path strings*/
		return (path_arr);
	}
	return (NULL);
}
