#include "shell.h"
/**
 * main - entry
 * Return: 0
 */

int main(int argc, char *argv[], char *envp[])
{
	char *msg;
	(void)argc;

	while (1)
	{	
		prompt();
		msg = _read();
		if (!msg)
		{
			exit(EXIT_SUCCESS);
		}
		if (msg[0] == '\0' || strcmp(msg, "\n") == 0)
		{
			free(msg);
			continue;
		}
		argv = tokenize(msg, " ");
		executes(argv, envp);
	}
	return (0);
}
