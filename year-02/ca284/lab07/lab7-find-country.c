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
void display_with_condition(Country *pc, int *pN);

int main(int argc, char *argv[]){

    Country c[50];
    int N = argc / 4;


    for(int i = 0; i < N; i++){
        fill_country(&c[i], argv + 1 + i*4);
    }

    //display(c, &N);
    display_with_condition(c, &N);
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

void display_with_condition(Country *pc, int *pN){
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
    for(int i = 0; i < *pN; i++){
        if((pc + i)->size < 100000)
            printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", (pc + i)->name, (pc + i)->capital, (pc + i)->size, (pc + i)->population);
    }
}

