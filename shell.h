#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
extern char **environ;

void prompt(void);
void _sprintf(const char *format);
void execute(char *argv[], char *env[]);
char **tokenize(char *str, char *delim);
char **_tokenize(char *str, char *delim);
char *_getenv(const char *msg);
void exec(char *argv[]);
char *_getpath(char *cmd);
ssize_t _getline(char **ptr, FILE *file);

#endif
