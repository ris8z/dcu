#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Country Country;

struct Country{
    char name[20];
    char capital[20];
    float population;
    int size;
};

void fill_country(Country *pc, char **pi);
void display(Country *pc, int *pN);
void sort(Country *pc, int N);
int find_index_max(Country *pc, int i, int j);
void swap(Country *pc, int i, int j);

int main(int argc, char *argv[]){

    Country c[50];
    int N = argc / 4;


    for(int i = 0; i < N; i++){
        fill_country(&c[i], argv + 1 + i*4);
    }

    sort(c, N);
    display(c, &N);

    return 0;
}

void fill_country(Country *pc, char **pi){
    strcpy(pc->name, *pi);
    strcpy(pc->capital, *(pi + 1));
    pc->population = atof(*(pi + 2));
    pc->size = atoi(*(pi + 3));
}

void display(Country *pc, int *pN){
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
    for(int i = 0; i < *pN; i++){
        printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", (pc + i)->name, (pc + i)->capital, (pc + i)->size, (pc + i)->population);
    }
}

void swap(Country *pc, int i, int j){
    Country tmp;
    tmp = *(pc + j);
    *(pc + j) = *(pc + i);
    *(pc + i) = tmp;
}


int find_index_max(Country *pc, int i, int j){
    float guess = (pc + i)->population;
    int idx = i;
    while(i <= j){
        if((pc + i)->population > guess){
            guess = (pc + i)->population;
            idx = i;
        }
        i++;
    };
    return idx;
}

void sort(Country *pc, int N){
    int idx;
    for(int i = 0; i < N - 1; i++){
        idx = find_index_max(pc, i, N - 1);
        swap(pc, i, idx);
    }
}
