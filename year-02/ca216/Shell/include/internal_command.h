//HEADER internal_command.h
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include "command.h"

extern char **environ;

int isInternal(char *s);
void runAsInternal(Command *c);
void funCD(Command *c);
void funPWD(Command *c);
void funDIR(Command *c);
void funCLR(Command *c);
void funENV(Command *c);
void funECO(Command *c);


