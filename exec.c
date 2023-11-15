#include "shell.h"
/**
 * executes - execute using execve
 * @argv: parameter
 * @env: parameter
 * Return: 0
 */
void executes(char *argv[], char *env[])
{
	pid_t pid_child;
	char *command, *cmd;
	int argc = 0;

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
			command = argv[0];

			cmd = _getpath(command);
			/* count the number of arguments */
			while (argv[argc])
				argc++;
		}

		if (argc != 1)
			cmd[0] = '\n'; /* cause error if argc != 1 */

		if (execve(cmd, argv, env) == -1)
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
