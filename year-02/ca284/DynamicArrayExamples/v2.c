#include<stdio.h>
#include<stdlib.h>

int *arr = NULL;
int count = 0;
size_t arr_size = 5;

void pre_alloc();
void push();
void pop();
void display();
void sort();

int main(int argc, char **argv){
    pre_alloc(); 
    push(5);
    push(10);
    push(11);
    display();
    pop();
    push(-2);
    push(4);
    display();
    sort();
    display();

    free(arr);
    return 0;
}

void pre_alloc(){
    arr = calloc(arr_size, sizeof(int));
    if(!arr)
        exit(0);
}

void push(int val){
    if(count >= arr_size){
        arr_size += 1;
        arr = realloc(arr, arr_size * sizeof(int));
        if(!arr)
            exit(0);
    }
    arr[count] = val;
    count += 1;
}

void pop(){
    if(count > 0){
        arr[count - 1] = 0;
        count -= 1;
    }
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
    int i,j,tmp;
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
