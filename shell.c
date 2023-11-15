#include "shell.h"
#include <string.h>

char **arrdup(char **arr);

/**
 * main - entry
 * @argc: number of commandline arguments
 * @argv: argument vector
 * @envp: environment variable
 * Return: 0
 */
int main(int argc, char *argv[], char *envp[])
{
	char *msg, *msg_dup, **argv_dup;
	(void) argc;

	while (1)
	{
		prompt();
		msg = _read();
		msg_dup = strdup(msg);

		if (msg_dup[0] == '\0' || strcmp(msg_dup, "\n") == 0)
		{
			free(msg);
			msg = NULL;
			free(msg_dup);
			msg_dup = NULL;
			continue;
		}
		else if (strcmp("exit", msg_dup) == 0)
		{
			free(msg);
			free(msg_dup);
			exit(EXIT_SUCCESS);
		}

		argv = _tokenize(msg_dup, " ");
		argv_dup = arrdup(argv);
		execute(argv_dup, envp);

		/* free allocated memory after use */
		free(msg);
		free(msg_dup);
		free(argv);
		free(argv_dup);
		msg = NULL;
		msg_dup = NULL;
		argv = NULL;
		argv_dup = NULL;
	}
	return (0);
}

/**
 * arrdup - duplicate array
 * arr: array to be duplicated
 * Return: new array with contents copied from arr
 */
char **arrdup(char **arr)
{
	/* arr must be NULL terminated */
	char **dup;
	size_t size = 0, i;

	if (arr == NULL)
		return (NULL);

	for (i = 0; arr[i]; i++)
		size += sizeof(arr[i]);

	size += sizeof(arr) + sizeof(arr[i]);
	dup = malloc(size);
	if (dup == NULL)
		return (NULL);
	i = 0;
	for (i = 0; arr[i]; i++)
		dup[i] = arr[i];
	dup[i] = arr[i];
	return (dup);
}
