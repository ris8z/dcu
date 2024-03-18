//HEADER utility.h
#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>



//CONSTANTS
    #define MAX_LINE_CHR 1024
    #define MAX_ARGU_NUM 64
    #define SEPARETORS " \t\n"
    #define OVER_WRITE 1 //to use with setenv


//GLOBAL VARS (note that utility.h is included also in command and internal command so environ is accessibale from everyfile)
    extern char **environ;


//FUNCTIONS
    void setShellPath(void);
    
    void checkForBatchMode(int argc,char** argv, FILE** pFile, bool* pFlag);
    bool validFile(char *filename);
    
    bool getNewLine(char *bufferLine, FILE *source);
    void printPrompt(void);
    void split(char **p, char *line, int *len); //split line in a list of string pointed by p
    void printLstString(char **p); //print a list of string pointed by p

    bool validSyntax(char **p, int len); //check if the syntax of command (as a list of its arguments)
    bool checkIvalidToken(char *s); //helper fucntion of validSyntax

    char **getArgs(char **p, int N);
    char* getInputFilename(char **p, int N);
    char* getOutputFilename(char **p, int N, bool *pAppend);
    bool getBackgroundMode(char **p, int N);


//define colors constant to for the printPrompt(void) function
    #define GREEN "\033[1;32m"
    #define CYAN  "\033[1;36m"
    #define NORMAL "\033[1;0m"
    //source: https://iq.opengenus.org/print-text-in-color-in-c/
