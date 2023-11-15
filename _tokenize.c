#include "shell.h"
#include <stdlib.h>
#include <string.h>

int contains(char *str, char c);

/**
 * count_toks - count the number of tokens in a string
 * @str: string
 * @delim: delimiter
 * Return: number of tokens
 */
size_t count_toks(char *str, char *delim)
{
	size_t i, num_tokens = 1;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (i == 0 || str[i + 1] == '\0')
			continue;

		if (contains(delim, str[i]) == 1)
		{
			if (contains(delim, str[i + 1]) != 1)
				num_tokens++;
		}
	}
	return (num_tokens);
}

/**
 * contains - check if a string contains a certain character
 * @str: string
 * @c: character
 * Return: 1 if char is found, otherwise return -1
 */
int contains(char *str, char c)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (1);
	}
	return (-1);
}

/**
 * _tokenize - break a string into an array of tokens
 * @str: string
 * @delim: delimiter
 * Return: array of strings
 */
char **_tokenize(char *str, char *delim)
{
	char *token, *tok_cpy, **tokens;
	size_t i, index = 0;
	size_t num_tokens = count_toks(str, delim);

	if (str == NULL || delim == NULL)
		return (NULL);

	tokens = malloc((num_tokens + 1) * sizeof(char *));
	if (tokens == NULL)
		return (NULL);

	token = (char *) malloc(strlen(str) + 1);
	if (token == NULL)
		return (NULL);

	num_tokens = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (contains(delim, str[i]) == 1)
		{
			if (i != 0 && contains(delim, str[i + 1]) != 1 && str[i + 1] != '\0')
			{
				token[index] = '\0';
				tok_cpy = strdup(token);
				tokens[num_tokens] = tok_cpy;
				free(token);
				index = 0;
				num_tokens++;
				token = (char *) malloc(strlen(str) + 1);
				if (token == NULL)
					return (NULL);
			}
			continue;
		}

		token[index] = str[i];
		index++;
	}
	token[index] = '\0';
	tok_cpy = strdup(token);
	tokens[num_tokens] = tok_cpy;
	tokens[num_tokens + 1] = NULL; /* last token is NULL */
	return (tokens);
}
