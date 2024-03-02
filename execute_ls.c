#include "main.h"

/**
 * execute_ls - executes ls command
 */
void execute_ls(void)
{
	int status;
	pid_t child_pid;
	char *argv[] = {"/bin/ls",  NULL};

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		exit(0);
	}
	else
	{
		wait(&status);
	}
}
