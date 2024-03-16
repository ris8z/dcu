#include "utility.h"
#include "command.h"
#include "internal_command.h"

int main(int argc, char **argv)
{
    setShellPath();
    FILE *input_source = stdin;
    char line_buffer[MAX_LINE_CHR];
    char *args_list_buffer[MAX_ARGU_NUM];
    int  args_len;
    bool batch_mode = false;
    Command *current_command;


    if( argc == 2 )
    {
        if( !validFile(argv[1]) ){
            printf("the batch file does not exist!\n");
            return 1;
        }
        input_source = fopen(argv[1], "r");
        batch_mode = true;
    }


    while( !feof(input_source) )
    {
        if( !batch_mode )
            printPrompt();


        if( getNewLine(line_buffer, input_source) )
        {
            split(args_list_buffer, line_buffer, &args_len);
            
            if( !validSyntax(args_list_buffer, args_len) )
                continue;
            
            current_command = buildCommand(args_list_buffer, args_len);

            if( current_command == NULL )
                continue;
           
            runCommand(current_command);


            free(current_command -> args);
            free(current_command);
        }
    }


    fclose(input_source);
    
    return 0;
}


