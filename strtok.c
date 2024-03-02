#include "main.h"

/**
 * my_strtok - splits a string into tokenns
 * @str: string to be split into token
 * @delim: constant character to split string
 * Return: points to null in the next token
 */
char *my_strtok(char *str, const char *delim)
{
	char *next_token = NULL;
	char *start_token;

	if (str != NULL)
		next_token = str;
	if (next_token == NULL || *next_token == '\0')
		return (0);
	start_token = next_token;
	while (*next_token != '\0')
	{
		if (strchr(delim, *next_token) != NULL)
		{
			*next_token = '\0';
			next_token++;
			break;
		}
		next_token++;
	}
	if (*next_token == '\0')
		next_token = NULL;
	return (start_token);
}
