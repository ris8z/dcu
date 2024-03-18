//SOURCE of interal_command.h
#include "internal_command.h"


//defining global variabile
int LEN = 9;

char *supported_commands[] = {
    "cd",
    "pwd",
    "dir",
    "clr",
    "environ",
    "echo",
    "help",
    "pause",
    "quit",
};

typedef void (*F)(Command *c);

F supported_f[9] = {
    &funCD,
    &funPWD,
    &funDIR,
    &funCLR,
    &funENV,
    &funECO,
    &funHLP,
    &funPAU,
    &funQUT,
};



//Helper fuctions
void setShellPath(void){
    char* start_dir = getenv("PWD");

    if( setenv("SHELL", start_dir, OVER_WRITE) != 0 )
        printf("Error with the change of the SHELL env variable\n");
}


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
    int old_output_fd = dup(STDOUT_FILENO);
    
    //change the file desc for output
    if( c -> output_file_des > 0 ){
        dup2(c -> output_file_des, STDOUT_FILENO);
    }

    //call the function
    supported_f[c -> is_internal](c);

    //restore the normal file desc
    if( c -> output_file_des > 0 ){
        dup2(old_output_fd, STDOUT_FILENO);
        close(c -> output_file_des);
        close(old_output_fd);
    }
}


//Implementation of all the internal functions
void funCD(Command *c){
    char* home = getenv("HOME");

    if( c -> args[1] )
    {
        if( chdir(c -> args[1]) == -1 ){
            printf("shell: %s is either not a directory or does not exits\n", c -> args[1]);
            return;
        }
    }
    else
    {
        chdir(home);
    }

    char newDir[256];
    getcwd(newDir, sizeof(newDir));
    
    if( setenv("PWD", newDir, OVER_WRITE) != 0 )
    {
        printf("Error with the change of the pwd variable\n");
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


void funHLP(Command *c)
{
    char command[256];

    char *command_name = "more -d";
    char *shell_path = getenv("SHELL");
    char *file_name = "readme.md";

    sprintf(command, "%s %s/%s", command_name, shell_path, file_name);

    system(command);
}


void funPAU(Command *c)
{
    printf("Press Enter to continue...\n");
    getc(stdin);
}


void funQUT(Command *c)
{
    exit(0);
}
