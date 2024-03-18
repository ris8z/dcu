/*
    author:         Giuseppe Esposito;
    
    stN:            22702205;
    
    date:           18/03/2024;
    
    description:    this is utility HEADER (it is the main one all the other header use function from here);

    approach:       is should contain all the fuction and utility regarding:
                    1) the start of the shell

                    2) getting and paresing input (puls printing the prompt if needed)

                    3) check for syntax error (very simple)
                        it is basically just one function validSyntax that use checkInvalidToken as helper 

                    4) helper Function to use with [buildCommand() in command.h]:
                        they just search for example, the inputfile name in the list of args or the & chr if we need backgroud mode,
                        All these command are just liner search, except getArgs() [see utility.c]

*/
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
    //START
    void setShellPath(void);
    void checkForBatchMode(int argc,char** argv, FILE** pFile, bool* pFlag);
    bool validFile(char *filename);
    
    //GETTING AND SPLITTING THE INPUT
    bool getNewLine(char *bufferLine, FILE *source);
    void printPrompt(void);
    void split(char **p, char *line, int *len); 
    void printLstString(char **p);//just for debug                                   

    //CHECK FOR SYNTAX ERRORS
    bool validSyntax(char **p, int len);        
    bool checkIvalidToken(char *s);

    //HELPER FUCNTIONS FOR buildCommand [in comand.h]
    char **getArgs(char **p, int N);
    char* getInputFilename(char **p, int N);
    char* getOutputFilename(char **p, int N, bool *pAppend);
    bool getBackgroundMode(char **p, int N);


//define colors constant to for the printPrompt(void) function
    #define GREEN "\033[1;32m"
    #define CYAN  "\033[1;36m"
    #define NORMAL "\033[1;0m"
    //source: https://iq.opengenus.org/print-text-in-color-in-c/
