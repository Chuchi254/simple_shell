#include "main.h"

/**
 * my_getline - reads a line from a file
 * @lineptr: poinner to line array
 * @size: size of line array
 * file: file to be read from
 * Return: number of line read
 */
ssize_t my_getline(char **lineptr, size_t *size, FILE *file)
{
	size_t capacity = *size;
	size_t s = 0;
	char *temp;
	int count;

	if (*lineptr == NULL)
	{
		*lineptr = malloc(capacity);
		if (*lineptr == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
	}

	while ((count = fgetc(file)) != EOF)
	{
		if (s >= capacity - 1)
		{
			capacity *= 2;
			temp = realloc(*lineptr, capacity);

			if (temp == NULL)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
			*lineptr = temp;
			*size = capacity;
		}
		(*lineptr)[s] = (char)count;
		s++;
		if (count == '\n')
			break;
	}
	(*lineptr)[s] = '\0';
	return (s == 0 && count == EOF ? -1 : (ssize_t)s);
}
