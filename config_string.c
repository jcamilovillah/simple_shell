#include "shell.h"
/**
 * arguments - separate string in arguments.
 * @s: is the string.
 * Return: 0 always.
 */
char **arguments(char *s)
{
        char **str, *token;
        int index = 0, count = 1;

        while (s[index])
        {
                if (s[index] == ' ')
                        count++;
                index++;
        }
        index = 0;
        str = malloc(count * sizeof(char *));
        if (!str)
        {
                write(STDERR_FILENO, ": allocation error\n", 20);
                exit(EXIT_FAILURE);
        }
        token = strtok(s, " ");
        while (token != NULL)
        {
                str[index] = token;
                index++;
                token = strtok(NULL, " ");
        }
        str[index] = NULL;
        count = 0;
        while (str[index - 1][count + 1])
                count++;
        str[index - 1][count] = '\0';
        return (str);
}
