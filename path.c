#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int pat_main(int argc, char *argv[])
{
	int i;
	char *ls_paths[] = {"/bin/ls", "/usr/bin/ls", NULL};

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s <arg1> [arg2] ...\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	for (i = 0; ls_paths[i] != NULL; i++)
	{
		if (access(ls_paths[i], X_OK) == 0)
		{
			argv[0] = ls_paths[i];
			if (execvp(ls_paths[i], argv) == -1)
			{
				perror("execvp");
				exit(EXIT_FAILURE);
			}
		}
	}

	fprintf(stderr, "ls command not found\n");
	exit(EXIT_FAILURE);

	return 0;
}
