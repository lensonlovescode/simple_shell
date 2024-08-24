#ifndef SHELL_H
#define SHELL_H


#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* execute file */
int create_process(char **args);

#endif
