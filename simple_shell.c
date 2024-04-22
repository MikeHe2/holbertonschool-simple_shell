#include "main.h"

/**
 * main - makes a prompt and waits for command
 * check if it handles empty line
 * Return: exits the prompt
 * getenv() google it
*/

int main(void)
{
	char *buffer = NULL;
	char *args[64];
	ssize_t read;
	pid_t child;
	size_t size = 0;
	extern char **environ;
	int i = 0, status = 0;
	char *token;

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
		else if (read == 0)
		{
			printf("\n");
			break;
		}

		buffer[read - 1] = '\0';

		
		token = strtok(buffer, " ");
    	while (token != NULL && i < sizeof(args) / sizeof(args[0]) - 1)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
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
			if (waitpid(child, &status, 0) == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
		}
	}
	return EXIT_SUCCESS;
}
