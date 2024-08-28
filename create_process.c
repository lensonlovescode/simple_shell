#include "shell.h"
/**
 * create_process - create a new process for a full path
 * @args: array of strings that contains the command and its flags
 * Return: 1 if sucess, 0 otherwise.
 */
int create_process(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("error in create_process: child process");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("error in create_process: forking");
		return (0);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
/**
 * handle_path_commands - handles commands not given as full paths
 * @args: array of commands
 * Return: returns 1 on success 0 on failure
 */
int handle_path_commands(char **args)
{
	pid_t pid;
	int status, i;
	char *path, **paths, *path_command;

	path = get_path();
	if (path == NULL)
	{
		return (0);
	}
	paths = get_tokens(path, ":");
	if (paths == NULL)
	{
		for (i = 0; paths[i] != NULL; i++)
		{
			free(paths[i]);
		}
		free(path);
		return (0);
	}
	path_command = check_builtin(paths, args[0]);
	if (path_command == NULL)
	{
		return (0);
	}
	for (i = 0; paths[i] != NULL; i++)
	{
		free(paths[i]);
	}
	free(paths);
	if (handle_path_commands2(path_command, args) == 1)
	{
		return (1);
	}
	return (0);
}
/**
 * handle_path_commands2 - continuation of the previous function
 * @path_command: full comand
 * @args: array of commands
 * Return: returns 1 on success 0 on failure
 */
int handle_path_commands2(char *path_command, char **args)
{
	pid_t pid;
	int status;

	if (path_command != NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(path_command, args, NULL) == -1)
			{
				free(path_command);
				exit(EXIT_FAILURE);
			}
		}
		else if (pid < 0)
		{
			free(path_command);
			return (0);
		}
		else
		{
			do {
				waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
		free(path_command);
		return (1);
	}
	perror(args[0]);
	return (0);
}
/**
 * checker - checks whether a command is a full path
 * @args: the array of commands/ command tokens
 * Return: 1 on successfull execution or 0 if no execution
 *
 */
int checker(char **args)
{
	if (**args == '/')
	{
		if (create_process(args) == 0)
		{
			perror("Create process:");
		}
		return (1);
	}
	else if (handle_builtin_commands(args) == 1)
	{
		return (1);
	}
	else
	{
		if (handle_path_commands(args) == 0)
		{
			return (0);
		}
	}
	return (0);
}
/**
 * path_concat - appends the command to the directory name
 * @directory: the directory
 * @command: the command to be appended
 * Return: returns the full path string
 */
char *path_concat(char *directory, char *command)
{
	int length;
	char *full_path;

	length = _strlen(directory) + strlen(command) + 2;

	full_path = malloc(length * sizeof(char));
	if (full_path == NULL)
	{
		return (NULL);
	}
	strcpy(full_path, directory);
	strcat(full_path, "/");
	strcat(full_path, command);
	return (full_path);
}
