//SOURCE of interal_command.h
#include "internal_command.h"


char *supported_commands[] = {
    "cd",
    "pwd",
};

typedef void (*F)(Command *c);

F supported_f[2] = {
    &funCD,
    &funPWD,
};

void funCD(Command *c){
    char* home = getenv("HOME");

    if( c -> args[1] )
    {
        chdir(c -> args[1]);
    }
    else
    {
        chdir(home);
    }

    char newDir[256];
    getcwd(newDir, sizeof(newDir));
    
    if( setenv("PWD", newDir, 1) != 0 )
    {
        printf("Error\n");
    }
    else
    {
        printf("Current working directory: %s\n", getenv("PWD"));
    }
}

void funPWD(Command *c)
{
    char buffer[256];
    printf("%s\n", getcwd(buffer, sizeof(buffer)));
}

