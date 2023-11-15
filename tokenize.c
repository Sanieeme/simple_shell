#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * tokenize - break a string into an array of tokens
 * @str: string
 * @delim: delimiter
 * Return: array of strings
 */
char **tokenize(char *str, char *delim)
{
	char *token, **tokens;
	size_t i, j;
	size_t num_tokens = 1; /* count the last token */

	if (str == NULL || delim == NULL)
		return (NULL);

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (delim[j] != '\0')
		{
			if (i == 0 || i == strlen(str) - 1 || str[i - 1] == delim[j])
				break;

			if (str[i] == delim[j])
			{
				num_tokens++;
				break;
			}
			++j;
		}
		++i;
	}

	tokens = malloc((num_tokens + 1) * sizeof(char *));
	if (tokens == NULL)
		return (NULL);

	i = 0;
	token = _strtok(str, delim);
	while (token != NULL)
	{
		tokens[i++] = token;
		token = _strtok(NULL, delim);
	}
	tokens[i] = token;/* last token is NULL */
	return (tokens);
}
