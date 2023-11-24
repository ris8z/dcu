#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Longest_line_file(char *filename, int *plongestlen, char (*pMaxline)[300]);

int main(){
    char *filename = "paragraph.txt";
    char longestline[300];
    int longestlen = 0;
    
    Longest_line_file(filename, &longestlen, &longestline);
    printf("%d\n", longestlen);
    printf("%s\n", longestline);

    return 0;
}


void Longest_line_file(char *filename, int *plongestlen, char (*pMaxline)[300]){
    FILE *pfile = NULL;
    pfile = fopen(filename, "r");
    if(!pfile)
        return;

    char buffer[300];
    int currLen;
    
    while(fgets(buffer, sizeof(buffer), pfile) != NULL){
        currLen = strlen(buffer);
        if(currLen > *plongestlen){
            *plongestlen = currLen;
            strcpy(*pMaxline, buffer);
        }
    }

    fclose(pfile);
    pfile = NULL;
}
