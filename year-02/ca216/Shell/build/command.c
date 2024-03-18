//SOURCE of HEADER command.h
#include "command.h"
#include "internal_command.h"
/*
I know that import internal_command.h insdie command.c does seem right, due too from my desing
internal_command is a subset of command, but to build a struct (see function BuildCommand())
i need the function isInternal(), and at least from me, have the function isInt4rnal in
internal_command.h make so much more sense than have it inside command.
*/



Command* newCommand(void)
{
    Command *result = malloc(sizeof(Command));

    if(result == NULL)
    {
        printf("Allocation error closing program...\n");
        exit(0);
    }

    result -> args = NULL;
    result -> input_file_des = 0;
    result -> output_file_des = 0;
    result -> background_mode = false;
    result -> is_internal = -1;

    return result;
}


Command* buildCommand(char **args_lst, int N)
{
    Command *result = newCommand();

    char *input_filename = NULL;
    char *output_filename = NULL;
    bool append = false;
    bool error = false;

    result -> args = getArgs(args_lst, N);

    input_filename  = getInputFilename(args_lst, N);
    result -> input_file_des = getInputFD(input_filename, &error);
    if( error )
        return NULL;
    
    output_filename = getOutputFilename(args_lst, N, &append);
    result -> output_file_des = getOutputFD(output_filename, append);

    result -> background_mode = getBackgroundMode(args_lst, N);

    result -> is_internal = isInternal(args_lst[0]);

    return result;
}

int getInputFD(char* filename, bool *pError)
{
    if( filename == NULL )
        return 0;
    
    if( !validFile(filename) )
    {
        printf("shell: %s: No such file or directory\n", filename);
        *pError = true;
        return 0;
    }

    return open(filename, O_RDONLY);
}


int getOutputFD(char* filename, bool append)
{
    //no output case
    if( filename == NULL )
        return 0;
    
    //append case >>
    if( append )
        return open(filename, O_APPEND | O_RDWR | O_CREAT, USER_PERMISSIONS);
    
    //trunc case >
    return open(filename, O_TRUNC | O_RDWR | O_CREAT, USER_PERMISSIONS);
}


void runCommand(Command *c)
{
    /*
    short des: it is a switch gate between internal command(the one with an actual implemntation in internal_command.c),
    and extrnal ones that (run with fork and  execv).
    */
    if( c -> is_internal != -1 ){
        runAsInternal(c);
        return;
    }
    
    runAsExternal(c);
}


void runAsExternal(Command *c)
{
    char *parent_entry = NULL;
    pid_t our_pid = fork();

    if( our_pid == FORK_FAILD )
        return;

    if( our_pid == CHILD )
    {
        //setting the entry: parent=(path of the shell)
        parent_entry = getenv("SHELL");

        if( setenv("PARENT", parent_entry, OVER_WRITE) != 0 )
            printf("Error with the change of the PARENT env variable\n");

        //change output and input file des if needed:
        if( c -> output_file_des > 0 )
        {
            dup2(c -> output_file_des, STDOUT_FILENO);
            close(c -> output_file_des);
        }

        if( c -> input_file_des > 0 )
        {
            dup2(c -> input_file_des, STDIN_FILENO);
            close(c -> input_file_des);
        }

        //call the execvp function
        execvp(c -> args[0], c -> args);
        
        printf("shell: invalid command or a crash by execvp function\n");
    }

    //PARENT PROCESS:

    if( c -> background_mode == false)
        waitpid(our_pid, NULL, 0);

    //wait if it is needed
    return;
}

void freeCommand(Command* c)
{
    free(c -> args);
    free(c);
}

void printCommand(Command *c)
{
    /*
    just for debug
    */

    printf("args       : ");
    if(c -> args != NULL)
    {
        printLstString(c -> args);
    }
    else
    {
        printf("[]\n");
    }
    printf("input  fd  : %d\n", c -> input_file_des);
    printf("output fd  : %d\n", c -> output_file_des);
    printf("backgroud  : %d\n", c -> background_mode);

}

