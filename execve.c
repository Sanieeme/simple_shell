#include "shell.h"
/**
 * execute - execute using execve
 * @argv: parameter
 * @env: environment variable
 * Return: 0
 */
void execute(char *argv[], char *env[])
{
	pid_t pid_child;
	char *command, *prog = getenv("_");
	int argc = 0;

	pid_child = fork();

	if (pid_child == -1)
	{
		perror(prog);
		exit(EXIT_FAILURE);
	}
	if (pid_child == 0)
	{
		if (argv)
		{
			command = argv[0];
			/* count the number of arguments */
			while (argv[argc])
				argc++;
		}

		if (argc != 1)
			command[0] = '\n'; /* cause error if argc != 1 */

		if (execve(command, argv, env) == -1)
		{
			perror(prog);
			exit(EXIT_FAILURE);
		}
		free(prog);
	}
	else
	{
		wait(NULL);
	}
}
