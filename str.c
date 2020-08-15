#include "shell.h"

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
* _strncat - concatenates two strings
* @src: First string to append
* @dest: Second string to append
* @n: number of bytes
* Return: Pointer to the resulting string
**/

char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	for (j = 0; j < n; j++, i++)
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
