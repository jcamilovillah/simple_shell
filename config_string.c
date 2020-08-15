#include "shell.h"
/**
 * arguments - separate string in arguments.
 * @s: is the string.
 * Return: 0 always.
 */
char **arguments(char *s)
{
	char **str, *token;
	int index = 0, count = 1;

	while (s[index])
	{
		if (s[index] == ' ')
			count++;
		index++;
	}
	index = 0;
	str = malloc(count * sizeof(char *));
	if (!str)
	{
		write(STDERR_FILENO, ": allocation error\n", 20);
		exit(EXIT_FAILURE);
	}
	token = strtok(s, " ");
	while (token != NULL)
	{
		str[index] = token;
		index++;
		token = strtok(NULL, " ");
	}
	str[index] = NULL;
	count = 0;
	while (str[index - 1][count + 1])
		count++;
	str[index - 1][count] = '\0';
	return (str);
}

/**
* _strcmp - compares to strings
* @s1: String #1
* @s2: String #2
* Return: number
**/

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/**
* _strcat - appends two strings
* @src: First string to append
* @dest: Second string to append
* Return: Pointer to the resulting string
**/

char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	for (j = 0; src[j] != '\0'; j++, i++)
	{
		dest[i] = src[j];
	}

	return (dest);
}
