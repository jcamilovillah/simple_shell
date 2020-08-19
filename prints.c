#include "shell.h"
/**
 * newline - print a new line.
 * @number: indicates whether to start the program or not.
 */
void newline(int number)
{
	(void)number;

	write(STDOUT_FILENO, "\nhsh$ ", 6);
}
/**
 * _putchar - print a string.
 * @c: string to print.
 */
void _putchar(char *c)
{
	int i = 0;

	while (c[i])
	{
		write(STDOUT_FILENO, &c[i], 1);
		i++;
	}
}
/**
 * printnumber - print a number.
 * @number: number to print.
 */
void printnumber(int number)
{
	int length = 0, aux = 1, i;
	char c;

	if (number < 0)
		write(STDOUT_FILENO, "-", 1);
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
			write(STDOUT_FILENO, &c, 1);
		}
		else
		{
			c = ((number / aux) % 10) + '0';
			write(STDOUT_FILENO, &c, 1);
		}
		number = number % aux;
		aux = aux / 10;
	}
}
/**
 * printerror - print error format.
 * @file: execution file.
 * @argv: user-given arguments.
 * @count: execution counter.
 * @message: error message to print.
 */
void printerror(char *file, char *argv, int count, char *message)
{
	_putchar(file);
	write(STDOUT_FILENO, ": ", 2);
	printnumber(count);
	write(STDOUT_FILENO, ": ", 2);
	_putchar(argv);
	write(STDOUT_FILENO, ": ", 2);
	_putchar(message);
	write(STDOUT_FILENO, "\n", 1);
}
