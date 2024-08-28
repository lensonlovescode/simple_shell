#include "shell.h"
/**
 * _strlen - calculates the length of a string
 * @str: the string whose length is to be calculated
 * Return: length of the string
 */
int _strlen(const char *str)
{
	int length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return length;
}
/**
 * _strcmp - compares two strings
 * @str1: the first string
 * @str2: the second string
 * Return: how much the strings differ, 0 if strings are the same
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
/**
 * _strcpy - copies a string from src to dest
 * @dest: the destination
 * @src: the source
 * Return: A pointer to the destination string
 */
char *_strcpy(char *dest, const char *src)
{
	char *ptr;
	ptr = dest;

	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (ptr);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination string
 * @src: string to be appended
 * Return: pointer to the final string
 */
char *_strcat(char *dest, const char *src)
{
	char *ptr;
	ptr = dest + _strlen(dest);
	while (*src)
	{
		*ptr++ = *src++;
	}
	*ptr = '\0';
	return (dest);
}
/**
 * _strdup - duplicates a string
 * @str: string to be duplicated
 * Return: pointer to the new string
 */
char *_strdup(const char *str)
{
	char *dup;
	int len;

	len = _strlen(str);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (dup == NULL)
	{
		return (NULL);
	}
	_strcpy(dup, str);
	return (dup);
}
/**
 * _strncmp - compares two strings up to n chars
 * @str1: the first string
 * @str2: the second string
 * @n: the number of characters
 * Return: how much they differ, 0 if ther are the same
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	while (n && *str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

