//HEADER internal_command.h
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "command.h"

extern char **environ;

void funCD(Command *c);
void funPWD(Command *c);

