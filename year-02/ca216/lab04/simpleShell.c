#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_BUFFER 1024
#define MAX_ARGS 64
#define SEPARATORS " \t\n"

int main(int argc, char **argv)
{
    char buf[MAX_BUFFER];   //line buffer
    char *args[MAX_ARGS];   //pointers to arg strings
    char **arg;             //working pointer
    char * prompt = ">> "; //shell prompt

    while(!feof(stdin)){
        
        fputs(prompt, stdout);

        if(fgets(buf, MAX_BUFFER, stdin)) {
            arg = args;
            *arg = strtok(buf, SEPARATORS);

            while(*arg){
                arg++;
                *arg = strtok(NULL, SEPARATORS);
            }

            if(args[0]){
                if(!strcmp(args[0], "clear") || !strcmp(args[0], "clr")){
                    system("clear");
                    continue;
                }

                if(!strcmp(args[0], "dir")){
                    char command[50] = "ls -al ";// max name for a folder 50 - 7 = 43chars
                    if(args[1]){
                        strcat(command, args[1]);
                    }
                    system(command);
                    continue;
                }

                if(!strcmp(args[0], "quit"))
                    exit(0);

                arg = args;
                while(*arg){
                    fprintf(stdout, "%s ", *arg);
                    arg++;
                    fputs("\n", stdout);
                }
            }
        }

    }



    return 0;
}
