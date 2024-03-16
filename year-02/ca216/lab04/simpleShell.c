#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h> //import of getcwd

#define MAX_BUFFER 1024
#define MAX_ARGS 64
#define SEPARATORS " \t\n"

extern char **environ;

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

                if(!strcmp(args[0], "environ")){
                    arg = environ;
                    while(*arg){
                        fprintf(stdout, "%s ", *arg);
                        arg++;
                        fputs("\n", stdout);
                    }
                    continue;
                }

                if(!strcmp(args[0], "pwd")){
                    char buffer[256];
                    printf("%s\n", getcwd(buffer, sizeof(buffer)));
                    continue;
                }

                if(!strcmp(args[0], "cd")){
                    //changeing the dir in the process
                    char* home = getenv("HOME");
                    if(args[1]){
                        chdir(args[1]);
                    }else{
                        chdir(home);
                    }
                    
                    //updating the PWD env var value
                    char newDir[256];
                    getcwd(newDir, sizeof(newDir));
                    if(setenv("PWD", newDir, 1) != 0){
                        printf("Erorr!\n");
                    }else{
                        printf("Current working directory: %s\n", getenv("PWD"));

                    }
                    continue;
                }

                if(!strcmp(args[0], "dir")){
                    char command[57] = "ls -al ";// max name for a folder 57 - 7 = 50chars
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
