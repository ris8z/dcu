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
	country c1;

	fill(&c1, argv + 1);
	print(c1);

	return 0;
}


void fill(country *p_c, char **p){
	strcpy((*p_c).name, *p);
	strcpy((*p_c).capital, *(p + 1));
	(*p_c).population = atof(*(p + 2));	
	(*p_c).size = atoi(*(p + 3));	
}

void print(country c){
	printf("%s\n", c.name);
	printf("%s\n", c.capital);
	printf("%.2f million people\n", c.population);
	printf("%d km2\n", c.size);
}
