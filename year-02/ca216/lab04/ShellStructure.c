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

char *get_input(char **p, int N);
char *get_output(char **p, int N, int *pAppend);
char **get_args(char **p, int N);
int get_backgroud(char **p, int N);


int main(int argc, char **argv){

    char current_line[MAX_LINE_CHR];                       //this is our buffer for holding the current line
    char *arguments[MAX_ARGU_NUM];                         //here we save the current line splitted in argument
    int  len_arg;                                          //len of the arguments

    char *command;
    char **args;
    char *input;
    char *output;
    int backgroud;
    int append;

    while(!feof(stdin)){

        print_prompt();

        if(get_new_line(current_line)){
            
            split_line_in_args(arguments, current_line, &len_arg);
            
            command = NULL;
            input = NULL;
            output = NULL;
            args = NULL;
            append = -1;
            backgroud = 0;

            if(!arguments[0])
                continue;

            command = arguments[0];
            args = get_args(arguments, len_arg);
            input  = get_input(arguments, len_arg);
            output = get_output(arguments, len_arg, &append);
            backgroud = get_backgroud(arguments, len_arg); 
            

            printf("command   : %s\n", command);
            printf("args      : ");
            print_arg(args);
            printf("input     : %s\n", input);
            printf("output    : %s\n", output);
            printf("append    : %d\n", append);
            printf("backgroud : %d\n\n\n", backgroud);
            
            
            free(args);
        }
        
    }
    return 0;
}
//it's quite long bc i want to get the possibility to have the args at the end of the command even after the input/output strem
char **get_args(char **p, int N){
    int i,j;
    int count = 0;

    for(i = 0; i < N; i++){
        //it's an oprator so not a vaild arg
        if( strcmp(p[i], "<") == 0 ||  strcmp(p[i], ">") == 0 ||  strcmp(p[i], ">>") == 0 ||  strcmp(p[i], "&") == 0){
            continue;
        }
        //it's the name of the input stream
        if( i > 0 && (strcmp(p[i - 1], "<") == 0)){
            continue;
        }
        //it's the name of the output stream
        if(i > 0 && (strcmp(p[i - 1], ">") == 0 ||  strcmp(p[i - 1], ">>") == 0 )){
            continue;
        }
        //evreything else should be a valid args (bc we dont cover pipes
        count += 1;
    }
    
    char **result = (char **)malloc(count * sizeof(char*));
    
    j = 0;
    for(i = 0; i < N; i++){
        if( strcmp(p[i], "<") == 0 ||  strcmp(p[i], ">") == 0 ||  strcmp(p[i], ">>") == 0 ||  strcmp(p[i], "&") == 0){
            continue;
        }
        if( i > 0 && (strcmp(p[i - 1], "<") == 0)){
            continue;
        }
        if(i > 0 && (strcmp(p[i - 1], ">") == 0 ||  strcmp(p[i - 1], ">>") == 0 )){
            continue;
        }
        //add the arg to the list
        result[j] = (char*)malloc(strlen(p[i]) + 1);
        strcpy(result[j], p[i]);
        j++;
    }
    result[j] = NULL; //null list string terminator
    return result;
}

char* get_input(char **p, int N){
    int i = 0;
    int add = 1;

    while(i < N && (strcmp(p[i], "<")) != 0){
        i++;
    }

    if( i + add < N){
        return p[i + add];
    }

    return NULL;
}

char* get_output(char **p, int N, int *pAppend){
    int i = 0;
    int add = 1;

    while(i < N && ((strcmp(p[i], ">")) != 0 && (strcmp(p[i], ">>"))) ){
        i++;
    }

    if( i + add < N){
        
        if((strcmp(p[i], ">>")) == 0){
            *pAppend = 1;
        }else{
            *pAppend = 0;
        }

        return p[i + add];
    }

    return NULL;
}

int get_backgroud(char **p, int N){
    int i = 0;
    int add = 1;

    while(i < N && (strcmp(p[i], "&")) != 0){
        i++;
    }

    if( i < N){
        return 1;
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

//it works only with list that end with a null terminator
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
    p++;
    *p = NULL;//null terminator
}
