#include "shell.h"
/**
 * create_process - create a new process
 * @args: array of strings that contains the command and its flags
 *
 * Return: 1 if sucess, 0 otherwise.
 */
int create_process(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
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
		do{
		   waitpid(pid, &status, WUNTRACED);
		}while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
