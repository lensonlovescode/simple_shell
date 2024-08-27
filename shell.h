#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

int create_process(char **args);
char *path_concat(char *directory, char *command);
char *check_builtin(char **directories, char *command);
char *get_path(void);
char **get_tokens(char *str, char *delim);
int checker(char **args);
int handle_path_commands(char **args);
#endif
