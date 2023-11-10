/*
    author = Giuseppe Esposito
    description = take an array as input and we display its largest element only if al least twice
    of one other element
    date = 9/11/2023
    approch =
    -we store dinamically the input with fill_array fuction
    -then we go through the whole array once recording the max and min value in two vars
    -we print the max if it greater then twice the min one else 0
*/
#include<stdio.h>
#include<stdlib.h>

void fill_array(int **p, int N, char **pi);
int largest_twice(int *p, int N);

int main(int argc, char **argv){
    int *pa = NULL;
    int N = argc - 1;

    fill_array(&pa, N, argv + 1);
    printf("%d\n", largest_twice(pa, N));
    return 0;
}

void fill_array(int **p, int N, char **pi){
    *p = (int*)malloc(N * sizeof(int));
    if(*p == NULL){
        printf("Memory Error\n");
        return;
    }

    for(unsigned int i = 0; i < N; i++)
        *(*p + i) = atoi(*(pi + i));
}

int largest_twice(int *p, int N){
    int guess_min = *(p);
    int guess_max = *(p);
    int n;

    for(unsigned int i = 0; i < N; i++){
        n = *(p + i);
        if(n > guess_max){
            guess_max = n;
        }
        if(n < guess_min){
            guess_min = n;
        }
    }

    if(guess_max > (2 * guess_min))
        return guess_max;

    return 0;
}
