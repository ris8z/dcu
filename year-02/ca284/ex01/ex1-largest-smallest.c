/*
author: Giuseppe Esposito;
description: given an array of number and a key string, it print the max element
of the array if the key is "largest" and the min if key is "smallest";
date: 5 oct 2023;
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//it returns the max value of an array
double max(double array[], int len);

//it returns the min value of an array
double min(double array[], int len);

//it returns 1 if the input key is "largest" and 0 otherwise
int which_key(char string[]);

int main(int argc, char *argv[])
{
	double input_array[50];
	int N = argc - 2;
	char key[9];

	//filling up the input var
	strcpy(key, argv[1]);
	for(int i = 0; i < N; i++){
		input_array[i] = atof(argv[2 + i]);
	}

	//checking which operation we have to do and print the result
	if(which_key(key) == 1){
		printf("%.2f\n", max(input_array, N));
	}else{
		printf("%.2f\n", min(input_array, N));
	}

	return 0;
}

int which_key(char string[]){
	if(strcmp(string, "largest") == 0){
		return 1;
	}else{
		return 0;
	}
}

double max(double array[], int len){
	/*we start saying that the first element is going to be our max
	then we loop all the element in the array if there is one bigger
	we update the value of result to that one.*/
	double result = array[0];
	
	for(int i = 0; i < len; i++){
		if(array[i] > result){
			result = array[i];
		}
	}
	return result;
}

double min(double array[], int len){
	/*same thing as max() function but we update the value of result
	if we find some smaller element.*/
	double result = array[0];
	
	for(int i = 0; i < len; i++){
		if(array[i] < result){
			result = array[i];
		}
	}
	return result;
}
