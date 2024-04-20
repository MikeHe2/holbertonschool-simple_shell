#include "main.h"

/**
 * 
 * 
 * 
 * 
 * 
*/

int get_command(char *token)
{
    pid_t son;

	son = fork();
	if (son < 0)
	{
		perror("fork failure");
		return(-1);
	}
	else if (son == 0)
	{
		if (execve(token[0], token, NULL) < 0)
		{
			printf("command not found\n");
		}
		exit(0);
	}
	else
	{
		wait(NULL);
	}
	return (0);
}