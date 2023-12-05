#include<stdio.h>
#include<stdlib.h>

int *arr = NULL;
size_t arr_size = 5;
int count = 0;


void pre_alloc();
void push(int n);
void display();
void sort();
void getInput(char **input, int N);
void countRep();

int main(int argc, char **argv){
    pre_alloc();
    getInput(argv + 1, argc - 1);
    sort();
    countRep();
    free(arr);
    return 0;
}

void pre_alloc(){
    arr = calloc(arr_size, sizeof(int));
    if(!arr)
        exit(0);
}

void push(int n){
    if(count >= arr_size){
        arr_size += 1;
        arr = realloc(arr, arr_size * sizeof(int));
        if(!arr)
            exit(0);
    }
    arr[count] = n;
    count += 1;
}

void display(){
    printf("[");
    for(int i = 0; i < count; i++){
        printf("%d", arr[i]);
        if(i != count - 1)
            printf(", ");
    }
    printf("]\n");
}

void sort(){
    int i, j, tmp;
    for(i = 0; i < count - 1; i++){
        for(j = 0; j < count - 1; j++){
            if(arr[j] > arr[j + 1]){
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void getInput(char **input, int N){
    for(int i = 0; i < N; i++){
        push(atoi(*(input + i)));
    }
}

void countRep(){
    int left = 0;
    int right = 0;
    int rep = 0;
    while(left < count){
        rep = 1;
        while(arr[left] == arr[right]){
            right += 1;
        }
        if(right - left > 3){
            for(int i = 0; i < right - left; i++)
                printf("%d\n", arr[left]);
        }
        left = right;
    }
}
