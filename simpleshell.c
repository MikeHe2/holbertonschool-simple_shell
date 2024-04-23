#include "shell.h"

int main(int argc __attribute__((unused)),
		char **argv __attribute__((unused)), char **envp)
{
	char *buffer = NULL;
	char *args[2];
	ssize_t read;
	pid_t child;
	size_t size = 0;

	printf("Welcome to simple_shell use it if you dare :)\n");

	while (1)
	{
		printf("$ ");
		read = getline(&buffer, &size, stdin);
		if (read == -1)
		{
			perror("C ya later! Don't forget your coffee!");/*ctrl + d*/
			exit(EXIT_FAILURE);
		}

		buffer[read - 1] = '\0';

		args[0] = buffer;
		args[1] = NULL;

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
				execve(path, args, envp); /*Pasamos envp como tercer argumento*/
			} else
			{
				printf("%s: command not found\n", buffer);

			}
			free(path);
			exit(EXIT_FAILURE);
		}	else
		{
			int status;

			if (waitpid(child, &status, 0) == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
		}
		return (EXIT_SUCCESS);
	}
}
