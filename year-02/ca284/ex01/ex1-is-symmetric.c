/*
author: Giuseppe Esposito;
description: given a string input from the commmand line check if it is a symmetric string;
date: 5 oct 2023;
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//it return 1 if the string is symm and 0 otherwhise
int is_symmetric(char string[], int len);

int main(int argc, char *argv[]){
	char input_string[50];
	int N;

	//filling up the input variables
	strcpy(input_string, argv[1]);
	N = strlen(argv[1]);

	//printing the output based on the fuction is_symmetric
	if(is_symmetric(input_string, N)){
		printf("yes\n");
	}else{
		printf("no\n");
	}

	return 0;
}

int is_symmetric(char string[], int len){
	/*I use two var i and j, i start to the starts of the string, while j starts to 
	the end, i loop unti i < j, by adding 1 to i and subtracting 1 to j;
	In each iteration I check if the two chars pointed by i and j are not the same,
	if it is the case return 0 (false),
	at the end of the loop if we didnt return the string must be symmetric, so
	return 1 (True)
	*/
	int i,j;
	
	i = 0;
	j = len - 1;

	while(i < j){
		if(string[i] != string[j]){
			return 0;
		}
		i++;
		j--;
	}

	return 1;
}
