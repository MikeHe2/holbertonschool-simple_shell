#include "shell.h"

/**
 * main - entry point
 * @args - arguments
 *
 */



int main(void) {
	char buffer[BUFFER_SIZE];
	char *args[2];
	ssize_t bytes_read;
	pid_t pid;

	while (1) {
		printf("#name$ ");

		bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		} else if (bytes_read == 0)
		{
			printf("\n");
			break;
		}

		buffer[bytes_read - 1] = '\0';

		args[0] = buffer;
		args[1] = NULL;

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		} else if (pid == 0)
		{
			execve(args[0], args, NULL);
			perror(buffer);
			exit(EXIT_FAILURE);
		} else
		{
			int status;
			if (waitpid(pid, &status, 0) == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
		}
	}

	return EXIT_SUCCESS;
}
