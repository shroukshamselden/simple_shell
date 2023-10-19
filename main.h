#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

#define NUM_ARGS 10
#define WRTE_BFF_SZE 1024
#define BUFF_FLSH -1
extern char **environ;
/**
 * struct lst_str - it is a singly linked list
 * @number : field of a number
 * @nxt : point at the following node
 */
typedef struct lst_str
{
	char *strr;
	int number;
	struct lst_str *nxt;
}list_t;

/**
 * struct pas_inf - some seudo_args to pass into a function
 *
 * @count_line : count err
 * @f_nam : it is a filename
 * @argv : arr of strs from arg
 * @argc : count of arg
 * @env : it isa a inked list.
 * @changed_env : if the environ was changed
 */

typedef struct pas_inf
{
	unsigned int count_line;
	char *f_nam;
	char **argv;
	list_t *env;
	int changed_env;
}inf_t;

void print_env(char **environ, int i);
void execute_command(char *a_rgv[NUM_ARGS], pid_t *pid, int *s_status);
int is_exit_command(char *command);
void write_string(char *str, int len);
char *read_command(char *comnd, size_t *buff_size);
void parse_command(char *comnd, char *a_rgv[NUM_ARGS]);
#endif
