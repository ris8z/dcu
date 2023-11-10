/*
    author = Giuseppe Esposito
    description = take as input two array from command line and print its doct product to standt output
    date = 9/11/2023
    approach = 
    -we dinamically store the input in two arrays pointed by pa1 and pa2 in the main
    -to obtain the result we just need to multiply each element of the first array with the second e sum these
    number up
    
*/
#include<stdio.h>
#include<stdlib.h>

void allocate_memory(int **p,int N);
void fill_array(int **pa1, int **pa2, int N, char **pi);
int dot_product(int *p1, int *p2, int N);
//void print_array(int *p, int N); just for debug

int main(int argc, char *argv[]){
    int *pa1 = NULL;
    int *pa2 = NULL;
    int N = atoi(argv[1]);

    fill_array(&pa1, &pa2, N, argv); 
    printf("%d\n", dot_product(pa1, pa2, N));

    free(pa1);
    free(pa2);
    pa1 = NULL;
    pa2 = NULL;

    return 0;
}

void allocate_memory(int **p, int N){
    *p = (int*)malloc(N * sizeof(int));
    if(*p == NULL){
        printf("Memory Error");
    }
}

void fill_array(int **pa1, int **pa2, int N, char **pi){
    allocate_memory(pa1, N);
    allocate_memory(pa2, N);

    if(*pa1 == NULL || *pa2 == NULL){
        return;
    }

    for(unsigned i = 0; i < N; i++){
        *(*(pa1) + i) = atoi(*(pi + 2 + i));
        *(*(pa2) + i) = atoi(*(pi + 2 + N + i));
    }
}

int dot_product(int *p1, int *p2, int N){
    int result = 0;
    for(unsigned i = 0; i < N; i++){
        result += (*(p1 + i)) * (*(p2 + i));
    }
    return result;
}

/*void print_array(int *p, int N){
    int *end = p + N;
    printf("[");
    for(;p < end; p++){
        printf("%d",*(p));
        if(p + 1 < end){
            printf(",");
        }
    }
    printf("]\n");
}*/
