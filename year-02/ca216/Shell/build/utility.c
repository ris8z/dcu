/*
    author:         Giuseppe Esposito;
    
    stN:            22702205;
    
    date:           18/03/2024;
    s
    description:    this is the source file of utility.h;

    approach:       more info in [utility.h]
*/
#include "utility.h"



//START
void setShellPath(void){
    char* start_dir = getenv("PWD");

    if( setenv("SHELL", start_dir, OVER_WRITE) != 0 )
        printf("Error with the change of the SHELL env variable\n");
}


void checkForBatchMode(int argc,char** argv, FILE** pFile, bool* pFlag){
    /*
    short desc: change the file pointer pointed by pFile if we are in batchmode, and it also turn on
    the flag pointed by pFlag.
    */
    if( argc != 2 )
        return;
    
    if( !validFile(argv[1]) )
    {
        printf("the batch file does not exist!\n");
        exit(1);
    }

    *pFile = fopen(argv[1], "r");
    if( *pFile == NULL){
        printf("error while opening the file!\n");
        exit(1);
    }
    *pFlag = true;
}


bool validFile(char *filename)
{
    FILE *fp = fopen(filename, "r");

    if( fp )
    {
        fclose(fp);
        return true;
    }
    
    return false;
}



//GETTING AND SPLITTING THE INPUT
bool getNewLine(char *bufferLine, FILE *source)
{
    if( fgets(bufferLine, MAX_LINE_CHR, source) )
    {
        return true;
    }
    
    return false;
}


void printPrompt(void)
{
    char *current_dir = getenv("PWD");
    fprintf(stdout, "\n%s%s%s\n>%s ", CYAN, current_dir, GREEN, NORMAL);
}


void split(char **p, char *line, int *len)
{   
    /*
        short des: split line in a list of string pointed by p using strtok,
        it is NULL terminated
    */
    *len = 0;
    *p = strtok(line, SEPARETORS);

    while( *p )
    {
        *len += 1;
        p += 1;
        *p = strtok(NULL, SEPARETORS);
    }    
}


void printLstString(char **p)//(JUST FOR DEBUG) works only with NULL terminated list
{    
    fprintf(stdout, "[");
    
    while( *p )
    {
        fprintf(stdout, "\"%s\"", *p);
        p += 1;

        if( *p )
            fprintf(stdout, ",");
    }

    fprintf(stdout, "]\n");
}



//CHECK FOR SYNTAX ERRORS
bool validSyntax(char **p, int len)
{
    /*
    Short desc: really simple syntax validator I just check if the input after (<, >>, <<) could be
    a valid name for a file (so it does not contain strage toknes like `@` `:` `%`) and i check
    if there is some pipes `|` that my shell do not handle
    */
    if( len == 0 )
        return false;

    for( int i = 0; i < len; i++ )
    {
        if( strcmp(p[i], "|") == 0 )
        {
            printf("shell: syntax error pipe do not supported `|`\n");
            return false;
        }

        if( strcmp(p[i], "<") == 0 && (i == len - 1 || checkIvalidToken(p[i + 1])) )
        {
            printf("shell: syntax error near unexpected token `<`\n");
            return false;
        }

        if( strcmp(p[i], ">") == 0 && (i == len - 1 || checkIvalidToken(p[i + 1])) )
        {
            printf("shell: syntax error near unexpected token `>`\n");
            return false;
        }

        if( strcmp(p[i], ">>") == 0 && (i == len - 1 || checkIvalidToken(p[i + 1])) )
        {
            printf("shell: syntax error near unexpected token `>>`\n");
            return false;
        }

    }

    return true;
}

bool checkIvalidToken(char *s)
{
    /*
    short des: help function of validSyntax, if in s there is just one of the invalid_tokens
    return true, else false
    */
    char *invalid_tokens[] = {
        "#",
        "%",
        "{",
        "}",
        "\\",
        "<",
        ">",
        "*",
        "?",
        "/",
        "$",
        "\'",
        "\"",
        ":",
        "@",
        "`",
        "|",
        "=",
    };
    
    int n = 18;

    for(int i = 0; i < n; i++)
    {
        if( strstr(s, invalid_tokens[i]) != NULL )
            return true;
    } 

    return false;
}



//HELPER FUCNTIONS FOR buildCommand [in comand.h]
char **getArgs(char **p, int N)
{
    /*
    disclaimer: it's quite long bc i want to get the possibility to have the args at the end of the command even after the input/output strem
    short des: 
        1)it goes once through the args list (already validated so in there should be just valid tokens), check how many argmuents needs to copy
        by incementing the var count.
        2)Then it goes through the all args again and this time copy selected strings in result.
        3)Add a null string to the end (because otherwaise execvp does not work)
        4)all the memory malloced here is freed by the command freeCommand [in command.h]
    */
    int i,j;
    int count = 0;
    char **result;

    for( i = 0; i < N; i++ )
    {
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
        //evreything else should be a valid args
        count += 1;
    }
    
    
    result = (char **)malloc(count * sizeof(char*));    
    j = 0;

    for( i = 0; i < N; i++ )
    {
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


char* getInputFilename(char **p, int N)
{
    /*
    short des: if in the args there is <, it returns the string of the input file name, else just NULL
    */

    int i = 0;
    int add = 1;

    while(i < N && (strcmp(p[i], "<")) != 0)
    {
        i++;
    }

    if( i + add < N)
        return p[i + add];

    return NULL;
}

char* getOutputFilename(char **p, int N, bool *pAppend)
{
    /*
    short des: if in the args there is >> or >, it returns the string of the output file name, else just NULL,
    and if there is a target, it change also the value of the pAppend flag (true if ">>" was found false otherwaise)
    */
    int i = 0;
    int add = 1;

    while(i < N && ((strcmp(p[i], ">")) != 0 && (strcmp(p[i], ">>"))) )
    {
        i++;
    }

    if( i + add < N)
    {
        
        if((strcmp(p[i], ">>")) == 0)
        {
            *pAppend = true;
        }
        else
        {
            *pAppend = false;
        }

        return p[i + add];
    }

    return NULL;
}


bool getBackgroundMode(char **p, int N)
{
    int i = 0;
    int add = 1;

    while(i < N && (strcmp(p[i], "&")) != 0)
    {
        i++;
    }

    if( i < N )
        return true;

    return false;
}
