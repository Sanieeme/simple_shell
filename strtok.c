#include "shell.h"
/**
 * _strtok - strtok
 * @str: string
 * @delim: a pointer to null terminated string
 * Return: pointer
 */
char *_strtok(char *str, const char *delim)
{
	static char *s = NULL;

	if (str != NULL)
		s = str;
	else if (!s)
		return;

	char *string = new char[strlen(s) + 1];

	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != delim)
			string[i] = s[i];
		else
		{
			string[i] = '\0';
			s = s + i + 1;
			return (string);
		}
	}
	string[i] = '\0';
	s = NULL;
	return (string);
}
