//HEADER utility.h
#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_CHR 1024
#define MAX_ARGU_NUM 64
#define SEPARETORS " \t\n"


bool validFile(char *filename);

bool getNewLine(char *bufferLine, FILE *source);

void printPrompt(void);

void split(char **p, char *line, int *len); //split line in a list of string pointed by p

void printLstString(char **p); //print a list of string pointed by p

bool validSyntax(char **p, int len); //check if the syntax of command (as a list of its arguments)

bool checkIvalidToken(char *s); //helper fucntion of validSyntax

char **get_args(char **p, int N);

char* get_input(char **p, int N);

char* get_output(char **p, int N, bool *pAppend);

bool get_background(char **p, int N);



#define RED "\033[1;30m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define CYAN  "\033[1;36m"
#define NORMAL "\033[1;0m"
