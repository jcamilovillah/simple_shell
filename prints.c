#include "shell.h"
/**
 * newline - print a new line.
 * @number: pues numero.
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
		count += write(STDIN_FILENO, &c[i], 1);
		i++;
	}
	return (count);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 */
void printnumber(int number)
{
	int length = 0, aux = 1, i;
	char c;

	if (number < 0)
		write(STDIN_FILENO, "-", 1);
	while (number / aux >= 10 || number / aux <= -10)
	{
		length++;
		aux = aux * 10;
	}
	for (i = 0; i <= length; i++)
	{
		if (number < 0)
		{
			c = -((number / aux) % 10) + '0';
			write(STDIN_FILENO, &c, 1);
		}
		else
		{
			c = ((number / aux) % 10) + '0';
			write(STDIN_FILENO, &c, 1);
		}
		number = number % aux;
		aux = aux / 10;
	}
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 */
void printerror(char *file, char **argv, int count, char *message)
{
	_putchar(file);
	write(STDIN_FILENO, ": ", 2);
	printnumber(count);
	write(STDIN_FILENO, ": ", 2);
	_putchar(argv[0]);
	write(STDIN_FILENO, ": ", 2);
	_putchar(message);
	write(STDIN_FILENO, " \n", 2);
}
