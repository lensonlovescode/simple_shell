#include "main.h"
#include <stdio.h>
#include <string.h>
char **get_tokens(char *str, char *delim)
{
	int i;
	int j;
	char *token;
	char **tokens;

	i = 0;

	tokens = (char *)malloc(10 * sizeof(char *));
	if (tokens == NULL)
	{
		return (NULL);
	}

	token = strtok(str, delim);

	while (token != NULL)
	{
		tokens[i] = (char *)malloc((strlen(token) + 1) * sizeof(char));
		if (tokens[i] == NULL)
		{
			for (int j = 0; j < i; j++)
			{
				free(tokens[j]);
			}
			free(tokens);
			return (NULL);
		}
		tokens[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
