#include "main.h"
#include <stdio.h>
#include <string.h>
char **get_tokens(char *str, char *delim)
{
	int i;
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
		tokens[i] = (char *)malloc(20 * sizeof(char));
		if (tokens[i] == NULL)
		{
			return (NULL);
		}
		token[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	return (tokens);
}
