//SOURCE FILE OF HEADER utility.h
#include "utility.h"


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
    char *name = "esposig2";
    fprintf(stdout, "%s >>", name);
}


void split(char **p, char *line, int *len)  //p is NULL terminated
{   
    *len = 0;
    *p = strtok(line, SEPARETORS);

    while( *p )
    {
        *len += 1;
        p += 1;
        *p = strtok(NULL, SEPARETORS);
    }    
}


void printLstString(char **p)//works only with NULL terminated list
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


bool validSyntax(char **p, int len)
{
    /*Really simple syntax validator I just check if the input after (<, >>, <<) cound be
    a valid name for a file (so it does not contain strage toknes like `@` `:` `%`) and i check
    if there is some pipes `|` that my shell do not handle*/
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


//it's quite long bc i want to get the possibility to have the args at the end of the command even after the input/output strem
char **get_args(char **p, int N)
{
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
        //evreything else should be a valid args (bc we dont cover pipes
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


char* get_input(char **p, int N)
{
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

char* get_output(char **p, int N, bool *pAppend)
{
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


bool get_background(char **p, int N)
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




