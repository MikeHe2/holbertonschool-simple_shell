#include "main.h"

/**
 * get_command - find the path to the command in the input given
 * 
 * @cmd: is the args[0] in main function
 * 
 * Return: full path if succesful NULL in failed
*/

char* get_command(char *cmd) 
{
  static char *locations[] = {"/bin", "/usr/bin", NULL};

  for (int i = 0; locations[i] != NULL; i++)
  {
    char *full_path = malloc(strlen(locations[i]) + strlen(cmd) + 2);
    sprintf(full_path, "%s/%s", locations[i], cmd);
    if (access(full_path, X_OK) == 0)
	{
      return full_path;
    }
    free(full_path);
  }

  return NULL;
}