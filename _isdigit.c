#include "shell.h"
/**
 * _isdigit - check if a character is a number.
 * @c: is the character.
 * Return: 1 digit or 0 otherwise.
 */
int _isdigit(char c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
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
