#include "shell.h"

/**
 * resize_memory - Resizes the memory block for the tokens array.
 * @ptr: Pointer to the current memory block.
 * @old_size: The current size of the memory block.
 * @new_size: The new desired size of the memory block.
 * Return: Pointer to the new memory block or NULL if it fails.
 */
char **resize_memory(char **ptr, size_t old_size, size_t new_size)
{
	char **new_ptr;
	size_t i;

	new_ptr = malloc(new_size * sizeof(char *));

	if (new_ptr == NULL)
		return (NULL);
	for (i = 0; i < old_size; i++)
		new_ptr[i] = ptr[i];
	free(ptr);
	return (new_ptr);
}

/**
 * get_tokens - Tokenizes a string based on delimiters.
 * @str: The input string to tokenize.
 * @delim: The delimiter characters used for tokenization.
 * Return: An array of tokenized strings or NULL if an error occurs.
 */
char **get_tokens(char *str, char *delim)
{
    int i, j, capacity;
    char *token, *str_copy;
    char **tokens;

    i = 0;
    capacity = 10;
    str_copy = _strdup(str);
    if (str_copy == NULL)
        return (NULL);

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
            tokens = resize_memory(tokens, i, capacity);
            if (tokens == NULL)
            {
                for (j = 0; j < i; j++)
                    free(tokens[j]);
                free(tokens);
                free(str_copy);
                return (NULL);
            }
        }

        tokens[i] = _strdup(token);
        if (tokens[i] == NULL)
        {
            for (j = 0; j < i; j++)
                free(tokens[j]);
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

