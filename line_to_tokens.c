#include "main.h"

/**
 *line_to_tokens - Function that Converts a string into
 *an array of tokens based on whitespace characters.
 *@line: array of strings
 *Return: the array of tokens.
 */
char **line_to_tokens(char *line)
{
	char *token = NULL, **line_arr = NULL;
	int i, counter = 0;
	/*counter the number of whitespace*/
	/*characters to determine array size*/
	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] != ' ' && line[i] != '\t')
			counter++;
	}
	/*counter++; */
	if (counter != 0)
	{
		/*Allocate memory for the array of tokens*/
		line_arr = malloc(sizeof(char *) * (counter + 1));
		if (line_arr == NULL) /*Handle memory allocation failure*/
			free(line), line = NULL, exit(EXIT_FAILURE);
	/*TTokenize the input line using space, newline, and tab as delimiters*/
		token = strtok(line, " \n\t");
		if (token == NULL) /*If no tokens were found*/
		{ /*Free the memory allocated for the input line*/
		free(line), line = NULL, free(line_arr), line_arr = NULL;
		return (NULL); /*NULL to indicate no tokens were processed*/
		}
		i = 0;
		while (token != NULL)
		{
			line_arr[i] = token;
			token = strtok(NULL, " \n\t");
			i++;
		}
		/*Mark the end of the array with a NULL pointer*/
		line_arr[i] = NULL;
	}
	/*Return the array of tokens*/
	return (line_arr);
}
