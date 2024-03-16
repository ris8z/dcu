//HEADER command.h
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h> 
#include <fcntl.h> 

typedef struct
{
    char **args;         // List of strings, to use with execv
    int input_file_des;  // Input  file descriptor, to use with dup2, 0 if there is no redirection
    int output_file_des; // Output file descriptor, to use with dup2, 0 if there is no redirection
    bool background_mode; // true if the command must run in back ground, to use with wait()
    int is_internal; // -1 if it is not intenal, else is the position of the linked fuctioin

} Command;


Command* newCommand(void);
Command* buildCommand(char **args_lst, int N);
void printCommand(Command *c);  //just for debug
