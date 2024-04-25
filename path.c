#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int pat_main(int argc, char *argv[])
{
	if (getenv("PATH") == NULL || strcmp(getenv("PATH"), "") == 0)
	{
		fprintf(stderr, "PATH is empty. Command execution is not possible.\n");
		return EXIT_FAILURE;
	}

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s <arg1> [arg2] ...\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (strcmp(argv[1], "ls") == 0)
	{
		if (execvp("ls", &argv[1]) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
        }
	}
	else
	{
		fprintf(stderr, "Command not supported: %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (0);
}

