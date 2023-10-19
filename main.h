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

void print_env(char **environ, int i);
void execute_command(char *a_rgv[NUM_ARGS], pid_t *pid, int *s_status);
int is_exit_command(char *command);
void write_string(char *str, int len);
char *read_command(char *comnd, size_t *buff_size);
void parse_command(char *comnd, char *a_rgv[NUM_ARGS]);

#endif
