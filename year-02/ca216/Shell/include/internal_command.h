//HEADER internal_command.h
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "command.h"


#define OVER_WRITE 1 //to use with setenv

extern char **environ;

void setShellPath(void);
int isInternal(char *s);
void runAsInternal(Command *c);
void funCD(Command *c);
void funPWD(Command *c);
void funDIR(Command *c);
void funCLR(Command *c);
void funENV(Command *c);
void funECO(Command *c);
void funHLP(Command *c);
void funPAU(Command *c);
void funQUT(Command *c);

