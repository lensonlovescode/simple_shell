#include "shell.h"
/**
* get_path - finds the path from the global environment
* Return: NULL if path is not found or path if path is found.
*/
char *get_path(void)
{
	char **env;
	char *path;

	path = NULL;
	env = environ;

	while (*env != NULL)
	{
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env + 5;
			return (path);
		}
		env++;
	}
	return (NULL);
}

