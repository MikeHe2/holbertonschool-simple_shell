#include "main.h"

/**
 * 
 * 
 * 
 * 
*/

char ** fail_safe(void)
{
    char **args;

    args = malloc(MAX_ARGS * sizeof(char *));
	if (args == NULL)
	{
		perror("Failed allocating memory");
		exit(EXIT_FAILURE);
	}
    return (args);
}