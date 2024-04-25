#include "main.h"

/**
 * 
 * 
 * 
 * 
 * 
 * 
*/

pid_t give_birth(char **args)
{
	pid_t child = fork();

	if (child == -1)
	{
		perror("fork not successful");
		free(args);
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		char *path = get_command(args[0]);

			if (path != NULL)
			{
				if (access(path, X_OK) == 0)
				{
					execve(path, args, environ);
					perror("execve");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				printf("%s: command not found\n", args[0]);
				free(path);
				exit(EXIT_FAILURE);
			}
	}
	return (child);
}
