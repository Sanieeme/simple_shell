#include "shell.h"
/**
 * _sprintf - printf
 *  @format: parameter
 *  Return: 0
 */
void _sprintf(const char *format)
{
	write(STDOUT_FILENO, format, strlen(format));
}
