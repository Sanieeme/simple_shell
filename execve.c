#include "shell.h"
/**
 * execute - execute using execve
 * @argv: parameter
 * Return: 0
 */
void execute(char **argv)
{
	pid_t pid_child;
	char *msg = NULL;

	pid_child = fork();

	if (pid_child == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid_child == 0)
	{
		if (argv)
		{
			msg = argv[0];
		}
		if (execve(msg, argv, NULL) == -1)
		{
			perror("simple_shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
