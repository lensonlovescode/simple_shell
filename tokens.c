#include "shell.h"

/**
 * get_tokens - Tokenizes a string based on delimiters.
 * @str: The input string to tokenize.
 * @delim: The delimiter characters used for tokenization.
 * Return: An array of tokenized strings or NULL if an error occurs.
 */
#include "shell.h"
char **get_tokens(char *str, char *delim)
{
        int i, j, capacity;
        char *token, *str_copy;
        char **tokens, **new_tokens;

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
                tokens[i] = _strdup(token);
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
