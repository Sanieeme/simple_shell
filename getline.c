#include "shell.h"
/**
 * _getline - own getline
 * @ptr: parameter
 * @file: parameter
 * Return: the number of characters read or -1 on failutre
 */
ssize_t _getline(char **ptr, FILE *file)
{
	int i = 0, len = 80;
	char n;

	char *buff = malloc(sizeof(char) * len);

	if (ptr != NULL)
		return (-1);
	if (i == len - 1)
	{
		char *temp = malloc(sizeof(char) * len * 2);

		strncpy(temp, buff, len);
		free(buff);
		len = len * 2;
	}
	n = fgetc(file);
	if (n == '\n' || n == EOF)
	{
		buff[i] = '\0';
	}
	else if (n == '\b' && n > 0)
	{
		i = i - 2;
	}
	else
	{
		buff[i] = n;
	}
	i++;

	*ptr = malloc(sizeof(char) * (i + 1));
	strncpy(*ptr, buff, i + 1);
	free(buff);
	return (i);
}
