#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include "main.h"

#define NUM_ARGS 10

extern char **environ; /* Declare environ*/

int main()
{ 
        pid_t pid;
        int s_status;
        ssize_t letrs;
        char *a_rgv[NUM_ARGS]; /* hold args of comnd included comnd itself*/
        int a_rgc;           /*number of args*/
        
        bool pipe = true;
        char* prompt = "cisfun$ ";
        char* ctrl = "^c\n";
        char* comnd = NULL;
        size_t buff_size = 0;
        while (1 && pipe)
        {
            if (isatty(STDIN_FILENO) == 0) /*check if we are using terminal or pipe*/
            {
                pipe = false;
            }
            write(1, prompt, 8);
            fflush(stdout);
        
            letrs = getline(&comnd, &buff_size, stdin);  /*waits use to write the comnd*/
        
            if (letrs == -1)
            {
                write(1, ctrl, 3); /*checks if getline fails or recieved ctrl+d*/
                free(comnd);
                exit(1);
            }
            if (comnd[letrs - 1] == '\n')
            {
                comnd[letrs - 1] = '\0';
            }
            a_rgc = 0;
            a_rgv[a_rgc] = strtok(comnd, " "); /*cut untill the first space u meet*/
            while(a_rgc < NUM_ARGS - 1 && a_rgv[a_rgc] != NULL )
            {
                a_rgc++;
                a_rgv[a_rgc] = strtok(NULL, " "); /*cut from the last space untill the second one*/
            }
            a_rgv[a_rgc] = NULL;

	     /* Check if the command is "exit"*/
            if (is_exit_command(a_rgv[0]))
            {
                free(comnd);
                exit(0);
            }

	    /* Check if the command is "env"*/
if (a_rgv[0][0] == 'e' && a_rgv[0][1] == 'n' && a_rgv[0][2] == 'v' && a_rgv[0][3] == '\0')
{
    /*Print the current environment variables*/
    int i = 0;
    while(environ[i]) {
        int len = 0;
        while(environ[i][len] != '\0') {
            len++;
        }
        write_string(environ[i], len);
        write(STDOUT_FILENO, "\n", 1);
        i++;
    }
}
            
            pid = fork(); /*create child process*/
            if (pid == -1)
            {
                perror("Error: fork has failed");
                free(comnd);
                exit(1);
            }
            if (pid == 0)
            {
                int val = execve(a_rgv[0], a_rgv, NULL);
                if (val == -1)
                {
                    perror("./shell");
                    free(comnd);
                    exit(1);
                }
            }

            if (waitpid(pid, &s_status, 0) == -1)
            {
                perror("Error: waitpid failed");
		free(comnd);
                exit(1);
            }
            
        }
        free(comnd);
        return 0;
}
