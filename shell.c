#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char **arrdup(char **arr);
int isempty(char *str);

/**
 * main - start simple_shell
 * @argc: number of command line arguments
 * @argv: argument vector
 * @envp: current environment
 * Return: 0
 */
int main(int argc, char *argv[], char *envp[])
{
	char *buf_dup, **argv_dup, *buffer = NULL;
	ssize_t nread = 0;
	size_t size = 0;
	int i, status;
	(void) argc;

	/* Read a line of text from the keyboard. */
	while (nread != -1)
	{
		if (isatty(STDIN_FILENO))
			prompt();

		nread = getline(&buffer, &size, stdin);
		if (nread != -1)
		{
			/* remove \n char at the end of buffer */
			buffer[strlen(buffer) - 1] = '\0';
			buf_dup = strdup(buffer);

			if (buf_dup[0] == '\0' || isempty(buf_dup) == 0)
			{
				free(buf_dup);
				continue;
			}

			argv = tokenize(buf_dup, " ");
			argv_dup = arrdup(argv);

			if (strcmp("exit", argv_dup[0]) == 0)
			{
				status = argv_dup[1] == NULL ? EXIT_SUCCESS : atoi(argv_dup[1]);
				free(buffer);
				free(buf_dup);
				free(argv);

				for (i = 0; argv_dup[i]; i++)
				{
					free(argv_dup[i]);
				}
				free(argv_dup[i]);
				free(argv_dup);
				exit(status);
			}
			execute(argv_dup, envp);

			/* free allocated memory */
			free(buffer);
			buffer = NULL;
			free(buf_dup);
			free(argv);

			for (i = 0; argv_dup[i]; i++)
			{
				free(argv_dup[i]);
			}
			free(argv_dup[i]);
			free(argv_dup);
		}
		else
		{
			if (buffer)
				free(buffer);
		}
	}
	printf("\n");
	exit(EXIT_SUCCESS);
}

/**
 * arrdup - duplicate array
 * @arr: array to be duplicated
 * Return: new array with contents copied from arr
 */
char **arrdup(char **arr)
{
	/* arr must be NULL terminated */
	char **arr_dup;
	size_t i, size = 0;

	if (arr == NULL)
		return (NULL);

	for (i = 0; arr[i]; i++)
		size += sizeof(arr[i]);

	size += sizeof(arr) + sizeof(arr[i]);
	arr_dup = malloc(size);
	if (arr_dup == NULL)
		return (NULL);

	for (i = 0; arr[i]; i++)
		arr_dup[i] = strdup(arr[i]);
	arr_dup[i] = arr[i];
	return (arr_dup);
}

/**
 * isempty - checks if a string is empty
 * @str: string
 * Return: 0 if string is empty, else returns number of non-whitespace chars
 */
int isempty(char *str)
{
	int i, c, res = 0;

	for (i = 0; str[i]; i++)
	{
		c = (int) str[i];
		if ((c < 9 || c > 13) && c != 32)
			res++;
	}
	return (res);
}
