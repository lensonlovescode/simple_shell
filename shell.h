#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * struct builtin - Struct to represent a shell builtin commands
 * @env: builtin command for printing the environment
 * @exit: builtin command for exiting the shell
 */
struct builtin
{
	char *env;
	char *exit;
};

extern char **environ;

int create_process(char **args);
char *path_concat(char *directory, char *command);
char *check_builtin(char **directories, char *command);
char *get_path(void);
char **get_tokens(char *str, char *delim);
int checker(char **args);
int handle_path_commands(char **args);
int handle_builtin_commands(char **args);
void print_env(void);
int _strlen(const char *str);
int _strcmp(const char *str1, const char *str2);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *str);
#endif
