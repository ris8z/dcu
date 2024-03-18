//SOURCE of HEADER command.h
#include "command.h"
#include "internal_command.h"



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

    char *input_file = NULL;
    char *output_file = NULL;
    bool append = false;


    result -> args = get_args(args_lst, N);

    input_file  = get_input(args_lst, N);
    if( input_file != NULL )
    {
        if( !validFile(input_file) )
        {
            printf("shell: %s: No such file or directory\n", input_file);
            return NULL;
        }
        result -> input_file_des = open(input_file, O_RDONLY);
    }
    
    
    output_file = get_output(args_lst, N, &append);
    if( output_file != NULL )
    {
        if( append )
        {
            result -> output_file_des = open(output_file, O_APPEND | O_RDWR | O_CREAT, 0644);
        }
        else
        {
            result -> output_file_des = open(output_file, O_TRUNC | O_RDWR | O_CREAT, 0644);
        }
    }

    result -> background_mode = get_background(args_lst, N);

    result -> is_internal = isInternal(args_lst[0]);

    return result;
}

void runCommand(Command *c)
{
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


void printCommand(Command *c)
{
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

