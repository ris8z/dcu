#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student Student;

struct student{
    char name[20];
    char college[20];
    int age;
    float grade;
};

void readData(Student *pStudent, char *filename);
void display_student(Student *p);

int main(int argc, char **argv){
    char *filename = "studentBinary.bin";
    Student S;
    
    readData(&S, filename);
    display_student(&S);

    return 0;
}


void readData(Student *pStudent, char *filename){
    FILE *pfile = NULL;
    int lenName, lenCollege;
    pfile = fopen(filename, "rb");
    if(!pfile){
        printf("File Error!\n");
        return;
    }
    
    int rcount1 = fread(&lenName, sizeof(int), 1, pfile); 
    int rcount2 = fread(pStudent->name, sizeof(char), lenName, pfile);

    int rcount3 = fread(&lenCollege, sizeof(int), 1, pfile); 
    int rcount4 = fread(pStudent->college, sizeof(char), lenCollege, pfile);

    int rcount5 = fread(&(pStudent->age), sizeof(int), 1, pfile);
    int rcount6 = fread(&(pStudent->grade), sizeof(float), 1, pfile);

    fclose(pfile);
    pfile = NULL;
}

void display_student(Student *p){
    printf("Name: %s\n", p->name);
    printf("College: %s\n", p->college);
    printf("Age: %d\n", p->age);
    printf("Grade: %.2f\n", p->grade);
}
