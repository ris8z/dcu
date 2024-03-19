/*
    author:         Giuseppe Esposito;
    
    stN:            22702205;
    
    date:           18/03/2024;
    
    description:    this is the main file of the shell, it puts all the pices together from the other header;

    approach:       the main() function is' divided in 3 part:
                    (delcare vars):
                        more info in the main function;

                    (run helper function for the shell):
                        such as setShellPath, and checkForBatchMode both from utility.h;
                    
                    (the main loop):
                        where it gets the input string  [using getNewLine from utility.h]
                        split it                        [using split from utility.h]
                        check for syntax errors         [using validSyntax from utility.h]
                        try to build a command instance [using buildCommand from command.h]
                        it runs the command             [using runCommand from command.h]
                        frees the unsed memory          [using freeCommand from command.h];
*/
#include "utility.h"
#include "command.h"
#include "internal_command.h"



int main(int argc, char **argv)
{
    FILE *input_source = stdin;             //the input source as default is stdin
    char line_buffer[MAX_LINE_CHR];         //buffer to get the line input for whatever input source in use (max line and argu const are defined in utiltity.h)
    char *args_list_buffer[MAX_ARGU_NUM];   //buffer to hold all the components of a command in a "lif of string" (pointer of pointer in reality)
    int  args_len;                          //len of the args_list_buffer
    bool batch_mode = false;                //flag for batch_mode
    Command *current_command;               //all the information need to run a command are in the Command strcut(see command.h)

    
    setShellPath();                                            //set the environ var SHELL
    checkForBatchMode(argc, argv, &input_source, &batch_mode); //it change the input source and batch flag if needed 

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
