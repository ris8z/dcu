#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// return 1 if the operator is divide or 0 otherwise
int is_division(char string[]);

// return n * m if flag == 0 or n / m otherwise
double calculator(int flag, double n, double m);

int main(int argc, char *argv[])
{
	double n1, n2;
	char operator[9];

	strcpy(operator, argv[1]);
	n1 = atof(argv[2]);
	n2 = atof(argv[3]);
	

	if (is_division(operator) && n2 == 0){
		printf("invalid\n");
	}else{
		printf("%f\n", calculator(is_division(operator), n1, n2));
	}

	return 0;
}


int is_division(char string[])
{
	if(strcmp(string, "divide") == 0){
		return 1;
	}else{
		return 0;
	}
}


double calculator(int flag, double n, double m)
{
	if(flag == 0){
		return n * m;
	}else{
		return n / m;
	}
}
