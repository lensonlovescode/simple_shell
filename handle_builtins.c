#include "shell.h"
/**
 * handle_builtin_commands - handles builtin commands
 * @args: tokenized command arguments
 * Return: 1 if a builtin command is executed, 0 otherwise
 */
int handle_builtin_commands(char **args)
{
	struct builtin builtin = {"env", "exit"};

	if (_strcmp(args[0], builtin.env) == 0)
	{
		print_env();
		return (1);
	}
	else if (_strcmp(args[0], builtin.exit) == 0)
	{
		exit(EXIT_SUCCESS);
		return (1);
	}
	return (0);
}
