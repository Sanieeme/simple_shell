#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void prompt(void);
void _sprintf(const char *format);
void execute(char *argv[], char *env[]);
char *_read(void);
char **tokenize(char *str, char *delim);

#endif
