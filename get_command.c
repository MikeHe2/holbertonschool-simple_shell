#include "main.h"

/**
 * 
 * 
 * 
 * 
 * 
*/

char* get_command(char *cmd_name) {
  // Check for the command in common locations (modify as needed)
  static char *locations[] = {"/bin", "/usr/bin", NULL};

  for (int i = 0; locations[i] != NULL; i++) {
    char *full_path = malloc(strlen(locations[i]) + strlen(cmd_name) + 2);
    sprintf(full_path, "%s/%s", locations[i], cmd_name);
    if (access(full_path, X_OK) == 0) {
      return full_path;
    }
    free(full_path);
  }

  // Check environment variable PATH (more complex parsing needed)
  // ...

  return NULL; // Executable not found
}