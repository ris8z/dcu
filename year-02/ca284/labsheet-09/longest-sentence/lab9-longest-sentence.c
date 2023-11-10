/*
    author = Giuseppe Esposito
    description = given an array of strings from command line input print only the longestS
    strings
    date = 9/11/2023
    approach =
    -I know that there are easier solution but i just want to play with triple pointers
    -we dinamically store all the input from command line in a matrix point from p in the main
    -we go one time trough the matrix to get the len of the longest string
    -then we go another time to print all the string with that lenght
    -and we free the matrix with a simple function
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void fill_up_matrix(char ***p, int N, char **pinput);
void find_max_len(char ***p, int N, int *p_result);
void display_longest(char ***p, int N, int KeyLen);
void free_matrix(char ***p, int N);

int main(int argc, char *argv[]){
    char **p = NULL;
    int N = argc - 1;
    int Maxlenght;

    fill_up_matrix(&p, N, argv + 1);
    find_max_len(&p, N, &Maxlenght);
    display_longest(&p, N, Maxlenght);
    free_matrix(&p, N);

    return 0;
}


void fill_up_matrix(char ***p, int N, char **pinput){
    *p = (char**)malloc(N * sizeof(char*));

    for(int i = 0; i < N; i++){
        *(*p + i) = (char*)malloc(strlen(*(pinput + i)) * sizeof(char));
        strcpy(*(*p + i), *(pinput + i));
    }
}

void find_max_len(char ***p, int N, int *p_result){
    *p_result = 0;
    for(int i = 0; i < N; i++){
        if(strlen(*(*p + i)) > *p_result){
            *p_result = strlen(*(*p + i));
        }
    }
}

void display_longest(char ***p, int N, int KeyLen){
    for(int i = 0; i < N; i++){
        if(strlen(*(*p + i)) == KeyLen){
            printf("%s\n", *(*p + i));
        }
    }
}

void free_matrix(char ***p, int N){
    for(int i = 0; i < N; i++){
        free(*(*p + i));
        *(*p + i) = NULL;
    }
    free(*p);
    *p = NULL;
}


