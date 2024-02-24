#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LINE_CHR 1024
#define MAX_ARGU_NUM 64
#define SEPARATORS " \t\n"

void print_prompt();                                       //display di prompt
int  get_new_line(char *line);                             //get and check a new line
void print_arg(char **p);                                  //print the args in a list style
void split_line_in_args(char **p, char *line, int *plen);  //split the current line in a list of argument

int main(int argc, char **argv){

    char current_line[MAX_LINE_CHR];                       //this is our buffer for holding the current line
    char *arguments[MAX_ARGU_NUM];                         //here we save the current line splitted in argument
    int  len_arg;                                          //len of the arguments
    char **p;                                              //working pointer

    char *command;
    char **args;
    char *input;
    char *output;

    while(!feof(stdin)){

        print_prompt();

        if(get_new_line(current_line)){
            
            split_line_in_args(arguments, current_line, &len_arg);
            print_arg(arguments);
            printf("%d\n", len_arg);
            
            command = NULL;
            input = NULL;
            output = NULL;
            args = NULL;

            if(!arguments[0])
                continue;

            command = arguments[0];
            
            int i = 0;
            while(i < len_arg && (strcmp(arguments[i], "<") != 0)){
                printf("%s\n", arguments[i]);
                i++;
            }

            if( i + 1 < len_arg){
                printf("< found AT %d\n", i);
                printf("input file : %s\n", arguments[i + 1]);
            }




        }
        
    }
    return 0;
}

void print_prompt(){
    char *name = "esposig2";
    fprintf(stdout, "%s >> ", name);
}

int get_new_line(char *line){
    if(fgets(line, MAX_LINE_CHR, stdin)){
        return 1;
    }
    return 0;
}

void print_arg(char **p){
    fprintf(stdout, "[");
    while(*p){
        fprintf(stdout, "\"%s\"", *p);
        p++;
        if(*p)
            fprintf(stdout, ",");
    }
    fprintf(stdout, "]\n");
}

void split_line_in_args(char **p, char *line, int *plen){
    *plen = 0;
    *p = strtok(line, SEPARATORS);
    while(*p){
        *plen += 1;
        p++;
        *p = strtok(NULL, SEPARATORS);
    }
}
