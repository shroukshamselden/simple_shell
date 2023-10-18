#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <unistd.h>

#define NUM_ARGS 10
extern char **environ;

int is_exit_command(char* command);
void write_string(char *str, int len);

#endif
