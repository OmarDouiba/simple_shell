#include"shell.h"
/**
 * main - the function that entry point of project simple shell
 *
 * @ac: number of command-line arguments
 * @argv: array of command-line arguments
 *
 * Return: 0
 */
int main(int ac, char **argv)
{
	char *nchars_read = NULL, *lineptr_copy = NULL;
	const char *delim = " \n";
	int num_tokens = 0;
	char *token;
	int i, j;
	(void)ac;

	while (1)
	{
		write(1, "$ ", 2);
		nchars_read = own_getline();
		if (nchars_read == NULL)
		{
			printf("end of file\n");
			break;
		}
		lineptr_copy = malloc(strlen(nchars_read) + 1);
		if (lineptr_copy == NULL)
		{
			perror(" memory allocation error");
			return (-1);
		}
		strcpy(lineptr_copy, nchars_read);
		token = strtok(nchars_read, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		argv = malloc(sizeof(char *) * (num_tokens + 1));
		token = strtok(lineptr_copy, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		execmd(argv);
		for (j = 0, j < num_tokens; j++)
		{
			free(arg[j]);
		}
		free(argv);
		free(lineptr_copy);
	}
	free(nchars_read);
        return (0);
}
