#include "shell.h"
/**
 * print_env - prints the environment variable
 * Return: Nothing
 */
void print_env(void)
{
	int x;
	char **env = environ;
	ssize_t bytes_written;
	int env_len;

	x = 0;

	while (env[x])
	{
		env_len = _strlen(env[x]);

		bytes_written = write(STDOUT_FILENO, (const void *)env[x], env_len);
		if (bytes_written == -1)
		{
			perror("Error writing environment variable");
			return;
		}
		bytes_written = write(STDOUT_FILENO, "\n", 1);
		if (bytes_written == -1)
		{
			perror("Error writing newline character");
			return;
		}
		x++;
	}
}

