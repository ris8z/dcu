#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

int main(int argc, char *argv[])
{
	int radius = 3;
	float area = 0.0;

	radius = radius*radius;

    	area  = radius*PI;

    	printf ("%.2f\n",area);
    	return (0);
}
