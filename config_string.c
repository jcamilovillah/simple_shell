#include "shell.h"
/**
 * arguments - separate the user's string into arguments.
 * @s: is the string.
 * Return: the string arguments.
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
	token = strtok(s, SEP_ESPAC);
	while (token)
	{
		str[index] = token;
		index++;
		token = strtok(NULL, SEP_ESPAC);
	}
	str[index] = NULL;
	count = 0;
	while (str[index - 1][count + 1])
		count++;
	str[index - 1][count] = '\0';
	return (str);
}
/**
 * check_string - verify that the string is not empty.
 * @str: is the string.
 * @length: string size.
 * Return: 1 if the string is valid, else 0.
 **/
int check_string(char *str, ssize_t length)
{
	ssize_t i = 0, count = 1;

	while (i < length)
	{
		if (str[i] == '\t'
				|| (str[i] == ' ' && str[i + 1] == ' ')
				|| (str[i] == ' ' && str[i + 1] == '\n'))
		{
			if (str[i] == '\t')
				str[i] = ' ';
			count++;
		}
		i++;
	}
	if (count == i)
		return (0);
	return (1);
}
/**
 * _strcmp - compare two strings.
 * @s1: string #1.
 * @s2: string #2.
 * Return: 0 if s1 and s2 are equal.
 **/
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
/**
 * _strcat - concatenate two strings.
 * @src: First string to append.
 * @dest: Second string to append.
 * Return: Pointer to the resulting string.
 **/
char *_strcat(char *dest, char *src)
{
	int i = 0, j;

	while (dest[i] != '\0')
		i++;
	for (j = 0; src[j] != '\0'; j++, i++)
		dest[i] = src[j];
	return (dest);
}
/**
 * _strdup - duplicate one string in another.
 * @str: is the string.
 * Return: the new duplicate string.
 **/
char *_strdup(char *str)
{
	int i = 0;
	char *cp;

	while (str[i])
		i++;
	cp = malloc(sizeof(char) * i);
	i = 0;
	while (str[i])
	{
		cp[i] = str[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
