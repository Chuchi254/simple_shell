#include "main.h"

/**
 * execute_ls - executes ls command
 */
void execute_ls(void)
{
	int count, status;
	pid_t child_pid;

	for (count = 0; count < 5; count++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
			printf("Child %d finished\n", count + 1);
			break;
		}
	}
}
