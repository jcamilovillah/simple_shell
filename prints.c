#include "shell.h"
/**
 * newline - print a new line.
 * Return: 0 always.
 */
void newline(int number)
{
	if (number == 1)
		write(STDIN_FILENO, "$shell ", 7);
	else
		write(STDIN_FILENO, "\n$shell ", 8);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 */
int _putchar(char *c)
{
	int count = 0, i = 0;

	while (c[i])
	{
		count += write(1, &c[i], 1);
		i++;
	}
	return (count);
}
