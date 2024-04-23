<<<<<<< HEAD
#include "shell.h"
#include <stdlib.h>
#include <string.h>

char *get_command(const char *command)
{
	char *locations[] = {"/bin/", "/usr/bin/", NULL};
	int i;
	char *full_path;

	for (i = 0; locations[i] != NULL; i++)
	{
		full_path = malloc(strlen(locations[i]) + strlen(command) + 2);
		if (full_path == NULL)
		{
			return NULL;
		}
		sprintf(full_path, "%s%s", locations[i], command);
		free(full_path);
	}
	return NULL;
}
