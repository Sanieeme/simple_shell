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
<<<<<<< HEAD
		if (strcmp(argv[0], "cd") == 0)
		{
			chdir(argv[1]);
			continue;
		}
		else if (strcmp(argv[0], "exit") == 0)
		{
			exit(0);
		}
		argv = tokenize(msg, "\n");
		execute(argv);
=======
		argv = tokenize(msg, " ");
		execute(argv, envp);
>>>>>>> d4db86c97a19b1793f4866010c066970cd72dfea
	}
	return (0);
}
