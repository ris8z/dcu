//HEADER command.h
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/wait.h>
#include "utility.h"

#define CHILD 0
#define FORK_FAILD -1
#define EXECVP_FAILD -1

typedef struct
{
    char **args;         // List of strings, to use with execv
    int input_file_des;  // Input  file descriptor, to use with dup2, 0 if there is no redirection
    int output_file_des; // Output file descriptor, to use with dup2, 0 if there is no redirection
    bool background_mode; // true if the command must run in back ground, to use with waitpid()
    int is_internal; // -1 if it is not intenal, else is the position of the linked fuctioin

} Command;


Command* newCommand(void);
Command* buildCommand(char **args_lst, int N);
void runCommand(Command *c);
void runAsExternal(Command *c);
void printCommand(Command *c);  //just for debug
