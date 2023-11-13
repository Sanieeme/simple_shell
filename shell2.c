#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **arrdup(char **arr);

int main(int argc, char *argv[], char *envp[])
{
	char *buf_dup, **argv_dup, *buffer = NULL;
	ssize_t nread = 0;
	size_t size = 0;
	int i;
	(void) argc;

	/* Read a line of text from the keyboard. */
	while (nread != -1)
	{
		prompt();
		nread = getline(&buffer, &size, stdin);

		if (nread != -1)
		{
			/* remove \n char at the end of buffer */
			buffer[strlen(buffer) - 1] = '\0';
			buf_dup = strdup(buffer);
			/*free(buffer);*/

			if (buf_dup[0] == '\0' || strcmp(buf_dup, "\n") == 0)
			{
				/* free(buffer); */
				free(buf_dup);
				continue;
			}

			argv = tokenize(buf_dup, " ");
			argv_dup = arrdup(argv);
			execute(argv_dup, envp);

			/* free allocated memory */
			printf("free allocated memory...\n");
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
		} else
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
 * arr: array to be duplicated
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

	i = 0;
	for (i = 0; arr[i]; i++)
		arr_dup[i] = strdup(arr[i]);
	arr_dup[i] = arr[i];
	return (arr_dup);
}
