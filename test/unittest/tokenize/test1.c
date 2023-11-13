#include "../../../shell.h"
#include <stdlib.h>

int main(void)
{
	char *str = NULL;
	char *delim = " ";
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
