#include "shell.h"
/**
 * main - entry
 * @argc: number of commandline arguments
 * @argv: argument vector
 * @envp: environment variable
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
<<<<<<< HEAD
		argv = tokenize(msg, " ");
		executes(argv, envp);
=======

		if (strcmp(argv[0], "cd") == 0)
		{
			chdir(argv[1]);
			continue;
		}
		else if (strcmp(argv[0], "exit") == 0)
		{
			exit(0);
		}

		argv = tokenize(msg, " ");
		execute(argv, envp);
>>>>>>> 3360ce2a714e5fabfa7537cea81d81e40e51a6c4
	}
	return (0);
}
