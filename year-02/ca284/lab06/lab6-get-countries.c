#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct country country;

struct country{
	char name[20];
	char capital[20];
	float population;
	int size;
};


void fill(country *p_c, char **p);

void print(country c);


int main(int argc, char **argv)
{
	country c[50];

	int N = (argc - 1) / 4;

	for(int i = 0; i < N; i++){
		fill(&c[i], argv + 1 + (i * 4));
	}	
	
	printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
	for(int i = 0; i < N; i++){
		print(c[i]);
	}
	return 0;
}


void fill(country *p_c, char **p){
	strcpy((*p_c).name, *p);
	strcpy((*p_c).capital, *(p + 1));
	(*p_c).population = atof(*(p + 2));	
	(*p_c).size = atoi(*(p + 3));	
}

void print(country c){
	printf("%s\t\t\t", c.name);
	printf("%s\t\t\t", c.capital);
	printf("%d\t\t\t", c.size);
	printf("%.2f\n", c.population);
}
