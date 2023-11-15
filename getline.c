#include "shell.h"
/**
 * _getline -
 * Return: the number of characters read or -1 on failutre
 */
ssize_t _getline(char **restrict ptr, size_t *restrict n, FILE *restrict file)
{
	if (ptr == NULL)
		return (-1);
	else if (n == NULL)
		return (-1);
	if (file == NULL)
		return (NULL);

	char *str;

	if (*ptr == NULL)
	{
		n = sizeof(str);
		if ((*ptr = malloc(*n)) == NULL)
		{
			return (-1);
		}
	}
	(*ptr)[0] = '\0';
}
