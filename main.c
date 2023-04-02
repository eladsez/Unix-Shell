/**
 * The main file of the Shell
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "shell.h"

pid_t main_pid;

extern size_t curr_history;

void SIGINT_handler (int sig) {
    if (main_pid != getpid()) exit(0);
    printf("You typed Control-C!\n");
}


int main(){
    main_pid = getpid();
    signal(SIGINT, SIGINT_handler);
    curr_history = init_history(NULL);
    print_dynamic_prompt();
    char *command = input_command();
    char *last_command = NULL;

    while (TRUE){
        if (!strncmp("quit", command, 4)){
            free(command);
            if (last_command != NULL) free(last_command);
            exit(0);
        }

        else if (!strncmp(command, "!!", 2) && last_command != NULL){
            free(command);
            command = last_command;
            continue;
        }

        else if (strlen(command) > 0){
            pipe_control(command);
            curr_history = init_history(command);
        } else {
            curr_history = init_history(NULL);
        }

        print_dynamic_prompt();
        if (last_command != NULL && command != last_command){
            free(last_command);
        }
        last_command = command;
        command = input_command();
    }
}

