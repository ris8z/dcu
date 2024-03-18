//HEADER internal_command.h
#pragma once
#include "command.h"




//GLOBAL(note that these vars are just declared, they are initialized in the source file "internal_command.c")
    extern int LEN;
    extern char *supported_commands[];
    typedef void (*F)(Command *c);
    F supported_f[9];


//FUNCTIONS
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