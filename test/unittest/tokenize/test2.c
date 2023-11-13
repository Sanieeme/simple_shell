#include "../../../shell.h"
#include <stdlib.h>

/**
 * main - test tokenize func with NULL delimeter
 *
 * Return: 0
 */
int main(void)
{
	char *str = "Merry Christmas and a Happy New Year";
	char *delim = NULL;
	char **tokens = tokenize(str, delim);
	int i = 0;
	
	if (tokens == NULL)
	{
		printf("Empty tokens list\n");
		return (-1);
	}
	while (tokens[i])
	{
		printf("%s\n", tokens[i]);
		i++;
	}
	free(tokens);
	return (0);
 }
