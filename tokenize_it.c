#include "main.h"

/**
 * 
 * 
 * 
 * 
*/

void tokenize_it(char *buffer, char **args)
{
    char *token;
    int i = 0;

    token = strtok(buffer, " \t");
    while (token != NULL && i < MAX_ARGS - 1)
    {
        args[i++] = token;
        token = strtok(NULL, " \t");
    }
    args[i] = NULL;
}