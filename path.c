#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int pat_main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <arg1> [arg2] ...\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (execvp("ls", argv) == -1)
	{
		perror("execvp");
		exit(EXIT_FAILURE);
	}

	return (0);
}
