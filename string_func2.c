#include "shell.h"
/**
 * _strcmp - compares two strings
 * @str1: the first string
 * @str2: the second string
 * Return: how much the strings differ, 0 if they're same
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

