/*
    aouthr = Giuseppe Esposito
    date = 14 dec 2023
    description = given a text find the longest or the shortest sentence
    apporach = we just go once trough the text and we save the longest and shortest length and the index of thier
    start so we can disply them without extra memory
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void display(char *string, int start, int end);//dispay a string from start to end 
void get_max_and_min(char *text, int *Biggest, int *Smallest, int *startS, int *startB);//get the max len and min and their starts index
void check(char *string);//check if the input is correct

int main(int argc, char **argv){
    int min_result = 100000000;
    int max_result = -100000000;
    int start_min = 0;
    int start_max = 0;

    check(argv[2]);
    get_max_and_min(argv[1], &max_result, &min_result, &start_min, &start_max);

    if(strcmp(argv[2],"shortest") == 0){
        printf("%d\n", min_result);
        display(argv[1], start_min, start_min + min_result - 1);
    }else{
        printf("%d\n", max_result);
        display(argv[1], start_max, start_max + max_result - 1);
    }

    return 0;
}

void display(char *string, int start, int end){
    for(int i = start; i <= end; i++){
        printf("%c", string[i]);
    }
    printf("\n");
}

void get_max_and_min(char *text, int *Biggest, int *Smallest, int *startS, int *startB){
    int we_are_reading = 0;
    int i = 0;
    int j;
    int start = 0;

    while(i < strlen(text)){
        if(text[i] != ' ' && we_are_reading == 0 && text[i] != 39){
            we_are_reading = 1;
            start = i;
            i += 1;

        }else if(text[i] == 39 && we_are_reading == 1){
            j = i + 1;
            while(j < strlen(text) && text[j] != 39){
                j += 1;
            }
            i = j + 1;

        }else if(text[i] == 39 && we_are_reading != 1){
            we_are_reading = 1;
            start = i;

            j = i + 1;
            while(j < strlen(text) && text[j] != 39){
                j += 1;
            }
            i = j + 1;
        
        }else if((text[i] == '.' || text[i] == '?') && we_are_reading == 1){
            if(*Biggest < i - start + 1){
                *Biggest = i - start + 1;
                *startB = start;
                
            }
            if(*Smallest > i - start + 1){
                *Smallest = i - start + 1;
                *startS = start;
            }
            we_are_reading = 0;
            i += 1;
        }else{
            i += 1;
        }
    }
}

void check(char *string){
    if(strcmp(string, "longest") != 0 && strcmp(string, "shortest") != 0){
        printf("Not valid!\n");
        exit(0);
    }
}
