//SOURCE of HEADER command.h
#include "command.h"
#include "utility.h"

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
            result -> output_file_des = open(output_file, O_CREAT | O_APPEND | O_WRONLY);
        }
        else
        {
            result -> output_file_des = open(output_file, O_CREAT | O_TRUNC | O_WRONLY);
        }
    }

    result -> background_mode = get_background(args_lst, N);


    return result;
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

