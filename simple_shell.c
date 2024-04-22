#include "main.h"

/**
 * main - makes a prompt and waits for command
 *
 * Return: exits the prompt
 * getenv() google it
*/

int main(void)
{
	char *buffer = NULL;
	char *args[2];
	ssize_t bytes_read, read;
	pid_t child;
	size_t size = 0;
	extern char **environ;

	printf("Welcome to simple_shell use it if you dare :)\n");

	while (1)
	{
		printf("$ ");
		read = getline(&buffer, &size, stdin);
		if (read == -1)
		{
			perror("C ya later! Don't forget your coffee!");//ctrl + d
			exit(EXIT_FAILURE);
		}

		buffer[read - 1] = '\0';

		args[0] = buffer;
		args[1] = NULL;
		if (strcmp(args[0], "exit") == 0)
		{
			break;
		}

		child = fork();
		if (child == -1)
		{
			perror("fork not succesful");
			exit(EXIT_FAILURE);
		}
		else if (child == 0)
		{
			char *path = get_command(args[0]);

			if (path != NULL) 
			{
				execve(path, args, environ);
				perror(buffer);
			}
			else
			{
				printf("%s: command not found\n", buffer);
			}
			free(path);
			exit(EXIT_FAILURE);
		}
		else
		{
			int status;
			if (waitpid(child, &status, 0) == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
		}
	}
	return EXIT_SUCCESS;
}
