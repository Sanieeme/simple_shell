#include "shell.h"
/**
 * _getpath - get path
 * @cmd: parameter
 * Return: NULL or path
 */

char *_getpath(char *cmd)
{
	char *path, *path_cpy, *_path, *file;
	struct stat st;
	int cmd_len, d;

	if (stat(cmd, &st) == 0)
		return (cmd);

	path = getenv("PATH");

	if (path && path[0] != '\0')
	{
		path_cpy = strdup(path);
		cmd_len = strlen(cmd);
		_path = strtok(path_cpy, ":");
		while (_path)
		{
			d = strlen(_path);
			file = malloc(cmd_len + d + 2);

			strcpy(file, _path);
			strcat(file, "/");
			strcat(file, cmd);
			strcat(file, "\0");
			if (stat(file, &st) == 0)
			{
				free(path_cpy);
				return (file);
			}
			else
			{
				free(file);
				_path = strtok(NULL, ":");
			}
		}
		free(path_cpy);
	}
	perror(getenv("_"));
	return (NULL);
}
