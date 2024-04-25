#ifndef MAIN_H 
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>

#define MAX_ARGS 64

char* get_command(char *cmd);
pid_t give_birth(char **args);
void tokenize_it(char *buffer, char **args);
void read_it(char **buffer, size_t *size);
char ** fail_safe(void);

extern char **environ;


#endif
