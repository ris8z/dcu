/*
    author = Giuseppe Esposito
    descprition = the program initially accepts an array of two students then check if the number of
    input students from the command lines is more than two,
    it allocate more memory so that all students info can be accommodated.
    date = 10/11/2023
    approach = 
    -our array of students i pointed by p in the main
    -we start by allocating two element with the basi_allocation function
    -then with the further_allocation one we check if we need to increase the size e if we need, we realloc
    -we store the input with fill_data
    -and we print it with display_students
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

void display_students(Student **p, int N);
void basic_allocation(Student **p, int *pSize, int *pFlag);
void further_allocation(Student **p, int *pSize, int *pFlag, int SizeNeeded);
void fill_data(Student **p, int size, char **pInput);

int main(int argc, char *argv[]){
    Student *p;
    int standardSize = 2;
    int ErrorFlag = 0;
    int SizeNeeded = (argc - 1) / 3;

    basic_allocation(&p, &standardSize, &ErrorFlag);
    if(ErrorFlag)
        return 1;

    further_allocation(&p, &standardSize, &ErrorFlag, SizeNeeded);
    if(ErrorFlag)
        return 1;

    fill_data(&p, standardSize, argv + 1);
    display_students(&p, standardSize);

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

void display_students(Student **p, int N){
    for(int i = 0; i < N; i++){
        printf("%s, ", (*p + i)->name);
        printf("%s, ", (*p + i)->programme);
        printf("%.2f\n", (*p + i)->grade);
    }
}
