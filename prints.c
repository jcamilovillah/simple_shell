#include "shell.h"
/**
 * newline - print a new line.
 * @number: indicates whether to start the program or not.
 */
void newline(int number)
{
	if (number == 1)
		write(STDIN_FILENO, "$shell ", 7);
	else
		write(STDIN_FILENO, "\n$shell ", 8);
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
		write(STDIN_FILENO, &c[i], 1);
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
 * printerror - print error format.
 * @file: execution file.
 * @argv: user-given arguments.
 * @count: execution counter.
 * @message: error message to print.
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
