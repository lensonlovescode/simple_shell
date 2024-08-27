#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
/**
 * main - main function
 * @ac: number of items in av
 * @av: NULL terminated array of strings
 * Return: returns 0
 */
char **get_tokens(char *str, char *delim);
int main(int ac, char **av)
{
	char *command;
	size_t length;
	size_t N_read;

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
		char **args = get_tokens(command," \t\n");
		checker(args);

		for (int i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free (args);
	}
	free(command);
	return 0;
	}
