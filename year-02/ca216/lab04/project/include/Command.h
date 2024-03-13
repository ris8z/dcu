#ifndef COMMAND_H
#define COMMAND_H

typedef struct{
    char** Args;        // List of strings, to use with execv
    int InputFileDes;   // Input  file descriptor, to use with dup2, 0 if there is no redirection
    int OutputFileDes;  // Output file descriptor, to use with dup2, 0 if there is no redirection
    int BackGroundMode; // 1 if the command must run in back ground else 0, to use with wait()
} Command;

#endif
