#include "shell.h"
char *_getenv(const char *msg)
{
	char *cmd, *k, *v, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		cmd = strdup(environ[i]);
		k = strtok(cmd, "=");
		if (strcmp(k, msg) == 0)
		{
			v = strtok(NULL, "=");
			env = strdup(v);
			free(cmd);
			return (env);
		}
		free(cmd);
	}
	return(NULL);
}
