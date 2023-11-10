/*
    author = Giuseppe Esposito
    description = given an array of strings from command line input print only the longestS
    strings
    date = 9/11/2023
    approach =
    -we store an array of lenght for each string in the command line
    -when we store the array we find also the max lenght
    -then we go through the all array another time and we print just the string with the longest len
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void fill_array(int **pa, int N, char **pi, int *pMaxVal);
void display_longest(int *paLen, char **pStr, int N, int value);

int main(int argc, char *argv[]){
    int *pa = NULL;//pointer to an array of lenghts
    int N = argc - 1;
    int maxvalue;
    
    fill_array(&pa, N, argv + 1, &maxvalue);
    display_longest(pa, argv + 1, N, maxvalue);

    free(pa);
    pa = NULL;

    return 0;
}

void fill_array(int **pa, int N, char **pi, int *pMaxVal){
    *pa = (int*)malloc(N * sizeof(int));

    if(*pa == NULL){
        printf("Memory Error");
        return;
    }
    
    int n;
    n = strlen(*(pi));
    *(*pa + 0) = n;
    *pMaxVal = n;

    for(unsigned int i = 1; i < N; i++){
        n = strlen(*(pi + i));
        *(*pa + i) = n;
        if(n > *pMaxVal){
            *pMaxVal = n;
        }
    }
}

void display_longest(int *paLen, char **pStr, int N, int value){
    for(int i = 0; i < N; i++){
        if(*(paLen + i) == value){
        printf("%s\n", *(pStr + i));
        }
    }
}
