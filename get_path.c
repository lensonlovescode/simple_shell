#include "shell.h"
/**
* get_path - finds the path from the global environment
* Return: NULL if path is not found or path if path is found.
*/
char *get_path(void)
{
	int i;
	char **env;
	char *path;

	path = NULL;
	env = environ;

	while (*env != NULL)
	{
		if (strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env + 5;
			for (i = 0; path[i] != '\0'; i++)
			{
				if (path[i] == ':')
				{
					path[i] = '\0';
					printf("full path:\n\n%s\n\n", path);
					return (path);
				}
			}
			printf("full path:\n\n%s\n\n", path);
			return (path);
		}
		env++;
	}
	return (NULL);
}
