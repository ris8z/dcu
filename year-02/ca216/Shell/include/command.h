//HEADER command.h
#pragma once
#include "utility.h"
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/wait.h>




//CONSTANTS
    #define CHILD 0
    #define FORK_FAILD -1
    #define EXECVP_FAILD -1
    #define USER_PERMISSIONS 0644 // to use with open(), while creating file so a user can both read and write that file 

//STRUCTS
    typedef struct
    {
        char **args;          // List of strings, to use with execv
        int input_file_des;   // Input  file descriptor, to use with dup2, 0 if there is no redirection
        int output_file_des;  // Output file descriptor, to use with dup2, 0 if there is no redirection
        bool background_mode; // true if the command must run in back ground, to use with waitpid()
        int is_internal;      // -1 if it is not intenal, else is the position of the linked fuctioin

    } Command;


//FUNCTIONS
    Command* newCommand(void);
    
    Command* buildCommand(char **args_lst, int N);
    int getInputFD(char* filename, bool *pError);
    int getOutputFD(char* filename, bool append);
    
    void runCommand(Command *c);
    void runAsExternal(Command *c);
    
    void freeCommand(Command* c);    
    void printCommand(Command *c);