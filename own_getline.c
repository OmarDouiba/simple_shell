#include"shell.h"
/**
 * *own_getline - function that read lines from the input
 *
 * Return: string
 */
char *own_getline()
{
	static char buffer[BUFFER_SIZE];
	static int index = 0;
	static int bytes_read = 0;
	int start_pos = index;

	if (index >= bytes_read)
	{
		bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		index = 0;
		if (bytes_read <= 0)
		{
			return NULL;
		}
	}

	while (index < bytes_read && buffer[index] != '\n')
	{
		index++;
	}
	if (index == bytes_read)
	{
		return NULL;
	}

	buffer[index++] = '\0';

	char *line = malloc(index - start_pos);

	if (line == NULL)
	{
		return NULL;
	}

	for (int i = start_pos; i < index; i++)
	{
		line[i - start_pos] = buffer[i];
	}

	return line;
}
