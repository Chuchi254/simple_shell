#include "main.h"

/**
 * main - super simple shell that executes commands without their full path
 *
 * Return: 0 Always
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		printf("$ ");
		nread = my_getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			else
			{
				perror("my_getline");
				exit(EXIT_FAILURE);
			}
		}
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		if (strcmp(line, "exec_ls") == 0 || strcmp(line, "//bin//ls"))
			execute_ls();
		else
			printf("Unknown command: %s\n", line);
	}
	free(line);
	return (0);
}
