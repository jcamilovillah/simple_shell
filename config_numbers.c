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
 * _atoi - convert a string to an integer.
 * @s: pointer.
 * Return: result entero.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int total = 0;
	char working = 0;

	while (*s)
	{
		if (*s == '-')
			sign = sign * -1;
		if (*s >= '0' && *s <= '9')
		{
			working = 1;
			total = total * 10 + *s - '0';
		}
		else if (*s < '0' || *s > '9')
		{
			if (working)
				break;
		}
		s++;
	}
	if (sign < 0)
		total = (-(total));
	return (total);
}
