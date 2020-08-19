#include "shell.h"
/**
 * _strcat - concatenate two strings.
 * @src: First string to append.
 * @dest: Second string to append.
 * Return: Pointer to the resulting string.
 **/
void _strcat(char *dest, char *src)
{
	int i = 0, j;

	while (dest[i])
		i++;
	for (j = 0; src[j]; j++, i++)
		dest[i] = src[j];
	dest[i] = '\0';
}
/**
 * _strlen - length of a string.
 * @s: pointer.
 * Return: result.
 */
int _strlen(char *s)
{
	int cifras = 0;

	while (*(s + cifras) != '\0')
		cifras++;
	return (cifras);
}
/**
 * _strcpy - copies the string pointed to by src.
 *
 * @dest: pointer.
 * @src: pointer.
 *
 * Return: void.
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
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
