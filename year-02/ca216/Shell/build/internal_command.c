//SOURCE of interal_command.h
#include "internal_command.h"


//defining global variabile
char *supported_commands[] = {
    "cd",
    "pwd",
    "dir",
    "clr",
    "environ",
    "echo",
};

typedef void (*F)(Command *c);

F supported_f[6] = {
    &funCD,
    &funPWD,
    &funDIR,
    &funCLR,
    &funENV,
    &funECO,
};

int LEN = 6;


//fuctions
int isInternal(char *s)
{
    int i = 0;
    while( i < LEN && !(strcmp(s, supported_commands[i]) == 0) )
    {
        i += 1;
    }

    if( i < LEN )
    {
        return i;
    }
    return -1;
}

void runAsInternal(Command *c)
{
    supported_f[c -> is_internal](c);
}

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

/* trying to implement it without using system it works
   but is so ugly
void funDIR(Command *c)
{
    struct dirent *current_file;
    DIR *current_dir;
    
    char path_cwd[256];
    getcwd(path_cwd, sizeof(path_cwd));

    current_dir = opendir(path_cwd);
    if( current_dir == NULL )
    {
        printf("Error while listing the current dir sorry...\n");
        return;
    }

    while( current_file = readdir(current_dir) )
    {
        if( current_file -> d_type != DT_DIR ){
            printf("file: %s\n", current_file -> d_name);
        }
        else
        {
            printf("dir:  %s\n", current_file -> d_name);
        }
    }

    closedir(current_dir);
}*/

void funDIR(Command *c)
{
    char command[256] = "ls -al ";
    
    if( c -> args[1] )
        strcat(command, c -> args[1]);
    
    system(command);
}

void funCLR(Command *c)
{
    system("clear");
}

void funENV(Command *c)
{
    char **p = environ;
    while( *p )
    {
        printf("%s\n", *p);
        p += 1;
    }
}

void funECO(Command *c)
{
    char **p = (c -> args) + 1;

    while( *p )
    {
        printf("%s ", *p);
        p += 1;
    }
    printf("\n");
}
