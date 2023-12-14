/*
    autoher = Giuseppe Esposito
    date = 14-dec-2023
    description: we are given a string we need to count the number of As and the number
    of seqeuence of 3 consecutive L

    approach: we just go once trough the sring when we encount A we add 1 to our result
    and when we encounter an L we use a two pointer approach to search when the
    sequence end, the length of sequence is just the seocnd pointer - the first one

    -we need also to take care of the edge case where there are multiple Ls like
    "LLLLLLA" we can just add another condition to the while loop to end when
    the distance between the two pointer is greater or equal then 3
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int countA(char *s);
void getInput(char **input, int N);
void solution(int N);

int main(int argc, char **argv){

    getInput(argv + 1, argc - 1);

    return 0;
}

int countA(char *s){
    int i;
    int j;
    int result = 0;

    i = 0;
    while(i < strlen(s)){
        if(s[i] == 'A'){
            result += 1;
            i += 1;
        }else if(s[i] == 'L'){
            j = i;
            while(j < strlen(s) && s[j] == 'L' && j - i < 3){
                j += 1;
            }

            if(j - i >= 3)
                result += 1;

            i = j;
        }else{
            i += 1;
        }
    }

    return result;
}

void getInput(char **input, int N){
    char buffer[51];
    for(int i = 0; i < N; i++){
        strcpy(buffer, *(input + i));
        solution(countA(buffer));
    }
}

void solution(int N){
    if(N >= 3){
        printf("1\n");
    }else{
        printf("0\n");
    }
}
