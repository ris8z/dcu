/*
    author = Giuseppe Esposito
    descprition = the program finds all CSCE students who have the higher grade than the average grade of all
    students and display their names and grads, along with the average grades up to 2 digits after
    the decimal point..
    date = 10/11/2023
    approach = 
    -its just the last es but we add two function
    -one to get the average of all the student
    -and another one to print only CSCE student with a grade higher the the average
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student Student;

struct student{
    char name[20];
    char programme[20];
    float grade;
};

void basic_allocation(Student **p, int *pSize, int *pFlag);
void further_allocation(Student **p, int *pSize, int *pFlag, int SizeNeeded);
void fill_data(Student **p, int size, char **pInput);
float get_average(Student **p, int size);
void print_CSCE(Student **p, int size, float ave);

int main(int argc, char *argv[]){
    Student *p;
    int standardSize = 2;
    int ErrorFlag = 0;
    int SizeNeeded = (argc - 1) / 3;
    float average;

    basic_allocation(&p, &standardSize, &ErrorFlag);
    if(ErrorFlag)
        return 1;

    further_allocation(&p, &standardSize, &ErrorFlag, SizeNeeded);
    if(ErrorFlag)
        return 1;

    fill_data(&p, standardSize, argv + 1);

    average = get_average(&p, standardSize);
    print_CSCE(&p, standardSize, average);

    return 0;
}

void basic_allocation(Student **p, int *pSize, int *pFlag){
    *p = (Student*)malloc(*pSize * sizeof(Student));
    if(*p == NULL){
        printf("Memory Allocation Error!\n");
        *pFlag = 1;
    }
}
        
void further_allocation(Student **p, int *pSize, int *pFlag, int SizeNeeded){
    if(*pSize > SizeNeeded)
        return;
    *pSize = SizeNeeded;

    Student *tmp;
    tmp = (Student*)realloc(*p, *pSize * sizeof(Student));
    if(tmp == NULL){
        printf("Memory Reallocation Error!\n");
        *pFlag = 1;
        free(*p);
        *p = NULL;
        return;
    }
    *p = tmp;
}

void fill_data(Student **p, int size, char **pInput){
    for(int i = 0; i < size; i++){
        strcpy((*p + i)->name, *(pInput + 0 + i * 3)); 
        strcpy((*p + i)->programme, *(pInput + 1 + i * 3)); 
        (*p + i)->grade = atof(*(pInput + 2 + i * 3));
    }
}

float get_average(Student **p, int size){
    float result = 0;
    for(int i = 0; i < size; i++){
        result += (*p + i)->grade;
    }
    return result / size;
}

void print_CSCE(Student **p, int size, float ave){
    for(int i = 0; i < size; i++){
        if((strcmp((*p + i)->programme, "CSCE") == 0) && ((*p + i)->grade > ave)){
            printf("%s, ", (*p + i)->name);
            printf("%.2f\n", (*p + i)->grade);
        }
    }
    printf("Average grade: %.2f\n", ave);
}
