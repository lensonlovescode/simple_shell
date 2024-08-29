#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
/**
 * main - main function
 * @ac: number of items in av
 * @av: NULL terminated array of strings
 * Return: returns 0
 */
int main(void)
{
	int i, N_read;
	char *command;
	char **args;
	size_t length;

	command = NULL;
	length = 0;
	while (1)
	{
		printf("$ ");
		N_read = getline(&command, &length, stdin);
		if (N_read == -1)
		{
			if (command == NULL)
			{
				perror("getline error");
				free(command);
				break;
			}
			else
			{
				putchar('\n');
				exit(98);
			}
		}
		if (N_read == 1 || (N_read > 1 && command[0] == '\n'))
			continue;
		args = get_tokens(command, " \t\n");
		if (args == NULL || args[0] == NULL)
		{
			free(args);
			continue;
		}
		checker(args);
		for (i = 0; args[i] != NULL; i++)
			free(args[i]);
		free(args);
	}
	free(command);
	return (0);
}

