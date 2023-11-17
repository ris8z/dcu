#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct City City;
typedef struct Country Country;

struct City{
    char name[20];
    float size;
};

struct Country{
    char name[20];
    City cities[3];
};

void fill_Country(Country *pc, char **pi);
void display(Country *pc, int *pN);
int find_min_idx(City *pc);

int main(int argc, char *argv[]){
    Country C[50];
    int N = argc / 7;
    
    for(int i = 0; i < N; i++){
        fill_Country(&C[i], argv + 1 + (i * 7));
    }
    display(C, &N);

    return 0;
}

void fill_Country(Country *pc, char **pi){
    strcpy(pc->name,*pi);
    for(int i = 0; i < 3; i++){
        strcpy(pc->cities[i].name, *(pi + 1 + (i * 2)));
        pc->cities[i].size = atof(*(pi + 2 + (i * 2)));
    }
}

void display(Country *pc, int *pN){
    int idx;
    for(int i = 0; i < *pN; i++){
        printf("%s: ",(pc + i)->name);
        idx = find_min_idx((pc + i)->cities);
        printf("%s\n", (pc + i)->cities[idx].name);
    }
}

int find_min_idx(City *pc){
    float guess = pc->size;
    int idx = 0;
    for(int i = 1; i < 3; i++){
        if(guess < (pc + i)->size){
            guess = (pc + i)->size;
            idx = i;
        }
    }
    return idx;
}
