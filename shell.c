#include "main.h"
/**
 * main - main function
 * @ac: number of items in av
 * @av: NULL terminated array of strings
 * Return: returns 0
 */
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
				printf("EOF\n\b");
				break;
			}
		}
		printf("%s", command);
	}
}
