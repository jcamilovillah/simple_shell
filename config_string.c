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
* check_string - compares to strings
* @str: String #1
* @length: String #2
* Return: number
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

/**
* _strcat - appends two strings
* @src: First string to append
* @dest: Second string to append
* Return: Pointer to the resulting string
**/
char *_strdup(char *str)
{
	int i = 0;
	char *cp;

	while(str[i])
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