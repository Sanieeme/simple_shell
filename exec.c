#include "shell.h"

/**
 * execute - execute using execve
 * @argv: parameter
 * @env: parameter
 * Return: 0
 */
void execute(char *argv[], char *env[])
{
	pid_t pid_child;
	char *command, *cmd, *prog;
	int status;

	command = argv[0];
	cmd = _getpath(command);
	
	if (cmd == NULL)
		exit(EXIT_FAILURE);

	prog = getenv("_");
	pid_child = fork();

	if (pid_child == -1)
	{
		perror(prog);
		exit(EXIT_FAILURE);
	}
	if (pid_child == 0)
	{
		if (execve(cmd, argv, env) == -1)
		{
			perror(prog);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		if (strcmp(command, cmd) != 0)
			free(cmd);
	}
}
