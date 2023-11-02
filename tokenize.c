#include "shell.h"
char **tokenize(char *msg)
{
	int counter = 0;
	char *token, *delimeter = "\n", **toks;
	char *buffer;

	token = strtok(buffer, delimeter);
	while (token)
	{
		toks[counter] = strdup(token);
		token = strtok(NULL, delimeter);
		counter++;
	}
	toks[counter] = token;
	/**if (strcmp(args[0], "cd") == 0)
	{
		chdir(args[1]);
		continue;
	}
	else if (strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}**/
}
