#include<stdio.h>
#include<stdlib.h>

#define PI 3.1415

int main(int argc, char *argv[])
{
	float radius = 0;
	float area = 0.0;
	radius = atoi(argv[1]);
	area = radius * radius * PI;
	
	printf("%.2f\n",area);
	//printf("%9.2f\n",area);

	return (0);
}
