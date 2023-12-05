#include<stdio.h>
#include<stdlib.h>


void pre_alloc(int **p, int *capacity);
void push(int **p, int *capacity, int *size, int N);
void getInput(int **p, int *size, int *capacity, char **inputi, int len);
void sort(int **p, int *size);
void printRipetition(int **p, int *size);
void printDataNtimes(int data, int N);

int main(int argc, char **argv){
    int *p = NULL;
    int size = 0;
    int capacity = 5;

    pre_alloc(&p, &capacity);
    getInput(&p, &size, &capacity, argv + 1, argc - 1);
    sort(&p, &size);
    printRipetition(&p, &size);

    free(p);
    p = NULL;
    return 0;
}

void pre_alloc(int **p, int *capacity){
    *p = (int*)malloc(sizeof(int) * (*capacity));
    if(!p)
        exit(0);
}

void push(int **p, int *capacity, int *size, int N){
    if(*size == *capacity){
        *capacity += 1;
        int *tmp = (int*)realloc(*p, sizeof(int) * (*capacity));
        if(!tmp){
            free(*p);
            *p = NULL;
            exit(0);
        }
        *p = tmp;
    } 
    (*p)[*size] = N;
    *size += 1;
}

void getInput(int **p, int *size, int *capacity, char **input, int len){
    int n;
    for(int i = 0; i < len; i++){
        n = atoi(*(input + i));
        push(p, capacity, size, n);
    }
}

void sort(int **p, int *size){
    int i, j, tmp;
    for(i = 0; i < *size - 1; i++){
        for(j = 0; j < *size - 1; j++){
            if((*p)[j] > (*p)[j + 1]){
                tmp = (*p)[j];
                (*p)[j] = (*p)[j + 1];
                (*p)[j + 1] = tmp;
            }
        }
    }
}


void printRipetition(int **p, int *size){
    int i = 0;
    int count = 0;
    while(i < *size){
        if(i == 0){
            count += 1;
        }else if((*p)[i] == (*p)[i - 1]){
            count += 1;
        }else{
            if(count > 3)
                printDataNtimes((*p)[i - 1], count);
            count = 1;
        }
        i += 1;
    }
    if(count > 3)
        printDataNtimes((*p)[i - 1], count);
}

void printDataNtimes(int data, int N){
    for(int i = 0; i < N; i++){
        printf("%d\n", data);
    }
}
