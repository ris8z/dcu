/*
    author:         Giuseppe Esposito;
    
    stN:            22702205;
    
    date:           18/03/2024;
    
    description:    this is the internal_command header file;

    approach:       for each internal command there is a dedicated function called fun + name of the command.

                    How do I check if a command is internal?
                        -there is a list of string called supported_commands, that contain all the name of the supported commands.
                        so it is just a linear serach.
                    
                    How do i run an internal command?
                        -linked to supported_commands there is another array (of pointer to function) called: supported_f
                        where each element at position Idx point to the specific fuctioion
                        that implements the command named supported_commands[Idx]

                        ex:
                        Suppose:
                            int Idx, and suppoted_finiction[Idx] = "cd"
                        Therefore:
                            suppoted_f[Idx] must point to the function that imnplement the cd command (supported_f[Idx] = &funCD)
                        In the end:
                            you just run by supported_f[Idx](c) where c is an istance of a command struct;
*/
#pragma once
#include "command.h"




//GLOBAL(note that these vars are just declared, they are initialized in the source file "internal_command.c")
    extern int LEN;
    extern char *supported_commands[];
    typedef void (*F)(Command *c);
    extern F supported_f[9];


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