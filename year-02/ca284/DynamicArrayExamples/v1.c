#include<stdio.h>
#include<stdlib.h>

void prealloc(int **p, int *size, int *capacity);
void push(int **p, int *size, int *capacity, int N);
void display(int **p, int *size);
void sort(int **p, int *size);

int main(int argc, char **argv){
    int *p = NULL;
    int size = 0;
    int capacity = 5;

    prealloc(&p, &size, &capacity);
    push(&p, &size, &capacity, 10);
    push(&p, &size, &capacity, 0);
    push(&p, &size, &capacity, 1);
    push(&p, &size, &capacity, 13);
    push(&p, &size, &capacity, 10);
    push(&p, &size, &capacity, 14);
    push(&p, &size, &capacity, 133);
    push(&p, &size, &capacity, -10);
    sort(&p, &size);
    display(&p, &size);

    return 0;
}
void prealloc(int **p, int *size, int *capacity){
    *p = (int*)malloc(sizeof(int) * (*capacity));
    if(!*p)
        exit(0);
}
void push(int **p, int *size, int *capacity, int N){
    if(*size >= *capacity){
        *capacity += 1;
        int *tmp = realloc(*p, sizeof(int) * (*capacity));
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

void display(int **p, int *size){
    for(int i = 0; i < *size; i++){
        printf("%d\n", (*p)[i]);
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
