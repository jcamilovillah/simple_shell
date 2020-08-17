#include "shell.h"
/**
 * _isdigit - checks for a digit
 * @c: number ASCII
 * Return: 1 digit or 0 otherwise.
 */
int _isdigit(char c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}