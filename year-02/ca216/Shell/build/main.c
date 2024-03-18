#include "utility.h"
#include "command.h"
#include "internal_command.h"



int main(int argc, char **argv)
{
    FILE *input_source = stdin;
    char line_buffer[MAX_LINE_CHR];
    char *args_list_buffer[MAX_ARGU_NUM];
    int  args_len;
    bool batch_mode = false;
    Command *current_command;

    setShellPath();
    checkForBatchMode(argc, argv, &input_source, &batch_mode);

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
            freeCommand(current_command);
        }
    }


    fclose(input_source);
    
    return 0;
}
