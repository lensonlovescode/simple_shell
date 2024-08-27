#include "shell.h"

char **get_tokens(char *str, char *delim)
{
	int i;
	int j;
	int capacity;
	char *token;
	char **tokens;
	char **new_tokens;
	char *str_copy;

	i = 0;
	capacity = 10;
	str_copy = strdup(str);

	if (str_copy == NULL)
	{
		return (NULL);
	}

	tokens = malloc(capacity * sizeof(char *));
	if (tokens == NULL)
	{
		free(str_copy);
		return (NULL);
	}

	token = strtok(str_copy, delim);

	while (token != NULL)
	{
		if (i >= capacity)
		{
			capacity *= 2;
			new_tokens = realloc(tokens, capacity * sizeof(char *));
			if (new_tokens == NULL)
			{
				for (j = 0; j < i; j++)
				{
					free(tokens[j]);
				}
				free(tokens);
				free(str_copy);
				return (NULL);
			}
			tokens = new_tokens;
		}

		tokens[i] = strdup(token);
		if (tokens[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(tokens[j]);
			}
			free(tokens);
			free(str_copy);
			return (NULL);
		}

		token = strtok(NULL, delim);
		i++;
	}

	tokens[i] = NULL;
	free(str_copy);
	return (tokens);
}

