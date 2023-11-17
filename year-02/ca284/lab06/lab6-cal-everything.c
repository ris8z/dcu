#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double sum(double a,double b);
double sub(double a,double b);
double pro(double a,double b);
double divv(double a,double b);
double poww(double a,double b);
double snl(double a,double b);

int main(int argc, char **argv)
{
	double a = atof(argv[1]);
	double b = atof(argv[2]);

	double (*p[6])(double, double) = {sum, sub, pro, divv, poww, snl};
	
	for(int i = 0; i < 6; i++)
		printf("%.2f\n", p[i](a,b));


	return 0;
}

double sum(double a,double b){
	return a + b;
}

double sub(double a,double b){
	return a - b;
}

double pro(double a,double b){
	return a * b;
}

double divv(double a,double b){
	return a / b;
}

double poww(double a,double b){
	return pow(a, b);
}

double snl(double a,double b){
	return log(a) + log(b);
}

