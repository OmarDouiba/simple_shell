#include"shell.h"
/**
 * *own_getline - function that read lines from the input
 *
 * Return: string
 */
char *own_getline()
{
	static char buffer[BUFFER_SIZE];
	static int index;
	static int bytes_read;
	int start_pos, i, nchars_read;

	if (index >= bytes_read)
	{
		bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		index = 0;
		if (bytes_read <= 0)
		{
			return (NULL);
		}
	}
	start_pos = index;
	while (index < bytes_read && buffer[index] != '\n')
	{
		index++;
	}
	if (index == bytes_read)
	{
		return (NULL);
	}
	buffer[index++] = '\0';
	char *line = (char *) malloc(index - start_pos);

	if (line == NULL)
	{
		return (NULL);
	}
	nchars_read = index - start_pos;
	for (i = start_pos; i < index; i++)
	{
		line[i - start_pos] = buffer[i];
	}
	return (line);
}
