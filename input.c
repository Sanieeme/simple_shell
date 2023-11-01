#include "shell.h"
/**
 * _read - read
 * Return: 0
 */
char *_read(void)
{
	char *msg = NULL;
	ssize_t size = 0;
	size_t n;

	n = getline(&msg, &size, stdin);
	if (n == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}
	return (msg);
}
