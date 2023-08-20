#include "shell.h"
/**
 * *get_location - function is expected to take in the command that was
 * passed and return the path of that command
 *
 * *command: a pointer to a null-terminated string
 * representing the name of a command
 *
 * Return: pointer to a char representing the location of the given command
 */

char *get_location(char *command)
{
	char *path, *dup_path, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		dup_path = strdup(path);
		command_length = strlen(command);
		path_token = strtok(dup_path, ":");
	
		while(path_token != NULL)
		{
			directory_length = strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(dup_path);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(dup_path);

		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}
