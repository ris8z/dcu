#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void check(int N, char **input);
void bin_to_dec(char **input, int N, int *pResult);
int two_pow_to(int N);

int main(int argc, char *argv[]){
    int N = argc - 1;
    int decN = 0;
    
    check(N, argv + 1);
    bin_to_dec(argv + 1, N, &decN);
    printf("%d\n", decN);

    return 0;
}

void bin_to_dec(char **input, int N, int *pResult){
    int tmp;
    for(int i = 0; i < N; i++){
        tmp = atoi(*(input + i));
        if(tmp == 1){
            *pResult += two_pow_to(N - 1 - i);
        }
    }
}

int two_pow_to(int N){
    int tmp = 1;
    for(int i = 0; i < N; i++){
        tmp *= 2;
    }
    return tmp;
}

void check(int N, char **input){
    if(N == 0){
        printf("One digit at least needed.\n");
        exit(0); 
    }
    if(N > 8){
        printf("Too many binary digits entered.\n");
        exit(0);
    }

    for(int i = 0; i < N; i ++){
        if(strcmp(*(input + i), "1") != 0 && strcmp(*(input + i), "0") != 0){
            printf("Only digits 1 and 0 are permitted.\n");
            exit(0);
        }   
    }
}
