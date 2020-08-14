#include "shell.h"
/**
 * main - the principal function for shell.
 * Return: 0 always.
 */
int main(int argc, char **argv)
{
	if (isatty(STDIN_FILENO))
		func_loop();
	else
		printf("%d\n", argc);
	return (0);
}
