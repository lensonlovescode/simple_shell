#include "shell.h"
/**
 * check_builtin - checks for the command in the list of directories in PATH
 * @directories: array os strings of the directories
 * @command: command to be searched for
 * Return: returns a string of the full path
 */
char *check_builtin(char **directories, char *command)
{
	int i = 0;
	char *full_command;

	while (directories[i] != NULL)
	{
		full_command = path_concat(directories[i], command);
		if (full_command == NULL)
		{
			return (NULL);
		}
		if (access(full_command, F_OK | X_OK) == 0)
		{
			return (full_command);
		}
		free(full_command);
		i++;
	}
	return (NULL);
}
