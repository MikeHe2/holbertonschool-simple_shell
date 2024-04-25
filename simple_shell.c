#include "main.h"

/**
 * main - makes a prompt and waits for command
 *
 * Return: exits the prompt
 *
 */

int main(void)
{
	char *buffer = NULL, **args = NULL;
	ssize_t read;
	pid_t child;
	size_t size = 0;
	int status = 0;

	args = fail_safe();

	while (1)
	{
		if (isatty(0))
			printf("$ ");

		read = getline(&buffer, &size, stdin);
		if (read == -1)
		{
			break;
		}
		if (read == 1 && buffer[0] == '\n')
			continue;

		buffer[read - 1] = '\0';

		tokenize_it(buffer, args);

		if (strcmp(args[0], "exit") == 0)
		{
			break;
		}
		child = give_birth(args);
		free(args);
	}
		 if (waitpid(child, &status, 0) == -1)
		{
            perror("waitpid");
            exit(EXIT_FAILURE);
        }
    return (0);
}
