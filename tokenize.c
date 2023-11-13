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
	size_t i = 0, num_tokens = 1; /* count the last token */

	while (str[i] != '\0')
	{
		if (str[i++] == delim[0])
			num_tokens++;
	}

	tokens = malloc((num_tokens + 1) * sizeof(char *));
	if (tokens == NULL)
		return (NULL);

	i = 0;
	token = strtok(str, delim);
	while (token != NULL)
	{
		tokens[i++] = token;
		token = strtok(NULL, delim);
	}
	tokens[i] = token;/* last token is NULL */
	return (tokens);
}
