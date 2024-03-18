//SOURCE of interal_command.h
#include "internal_command.h"



//INITIALIZE GLOBAL VARS
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


//FUNTIONS IMPLEMENTAION:
int isInternal(char *s)
{
    /*
    short des: check if the string s is the name of one of the internal supported commands with a liner search.
    return   : -1 if s is not a internal function, or the position of that string in the supported_commands array.
    */

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
    /*
    short des: run an internal command, by calling its fuction through the array of function pointer (supported_f),
    using the index stored in the field (is_internal) of the command structure (that is just the return value of the function isInternal() above here)
    and change the output file descriptor if needed.
    */

    //save the stadard output file descriptor if we need to restre it
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


void funCD(Command *c){

    /*
    short desc: this function implement the command CD, if we have an agrs[1] we try to change dir to that one, but if there is no args[1] we
    change dir to the home, that we get from the global environ vars.
    And it also over write the PWD var with the new path.
    */

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
    /*
    short des: just print the current working dir with the function getcwd()
    */

    char buffer[256];
    printf("%s\n", getcwd(buffer, sizeof(buffer)));
}


void funDIR(Command *c)
{
    /*
    short des: display the list of files in the cwd by using system() call
    */

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
    /*
    short des: it prints the manual with the more filter, for printing it we need the path of readme.md, that is the same folder of the shell
    so we just use (SHELL environ var) that we set at the start of the porgram with setShellPath();
    */
    
    char command[256];

    char *command_name = "more -d";
    char *shell_path = getenv("SHELL");
    char *file_name = "readme.md";

    sprintf(command, "%s %s/%s", command_name, shell_path, file_name);

    system(command);
}


void funPAU(Command *c)
{
    /*
    short des: it pause the termial, by wating for a char to be press(with getc()).
    */
    printf("Press Enter to continue...\n");
    getc(stdin);
}


void funQUT(Command *c)
{
    exit(0);
}
