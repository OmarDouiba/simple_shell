#include "shell.h"
/**
* _strlen - returns the length of a string
*
* @s: string
*
* Return: length
*/
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

/**
* *_strcpy - copies the string pointed to by src
*
* @dest: copy to
* @src: copy from
*
* Return: dest
*/
char *_strcpy(char *dest, const char *src)
{
	int y = 0;

	int z = 0;

	while (*(src + y) != '\0')
	{
		y++;
	}
	for (; z < y; z++)
	{
		dest[z] = src[z];
	}
	dest[y] = '\0';
	return (dest);
}

/**
* *_strcat - concatenates two strings
*
* @dest: string
* @src: string
*
* Return: dest
*/
char *_strcat(char *dest, char *src)
{
	int i, e;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	e = 0;
	while (src[e] != '\0')
	{
		dest[i] = src[e];
		i++;
		e++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * *strdup - function that duplicate string to new_string
 *
 * @*s: string duplicated
 *
 * Return: a pointer to a new string
 */
char *strdup(const char *s)
{
	size_t len = strlen(s) + 1;

	char *new_str = (char *)malloc(len);

	if (new_str != NULL)
	{
		strcpy(new_str, s);
	}
	return new_str;
}
