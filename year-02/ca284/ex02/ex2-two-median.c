/*
	author: Giuseppe Esposito;
	description: this program take an array as input from command line
	sort it, and print its two middle elements;
	date: 02/11/2023;
	approach:
	-first fill the array using pointers
	-sorting it using pointers
	-just print out the (n/2 - 1) element and then the (n/2) element of the array
*/
#include<stdio.h>
#include<stdlib.h>

void fill_array(int *p, int *p_N, char **p_input);
void sort_array(int *p, int *p_N);
void display_middle_two(int *p, int *p_N);
//void display(int *p, int *p_N); //used just for debug

int main(int argc,char *argv[]){
	int array[100];
	int N = argc - 1;
	
	fill_array(array, &N, argv + 1);
	sort_array(array, &N);
	display_middle_two(array, &N);

	
	return 0;
}



void fill_array(int *p, int *p_N, char **p_input){
	/*we go through the input one time a we fill the array using the pointer p to
	record the address of the element of the arrat in the main and p_input record the
	address of the element in argv*/
	for(int i = 0; i < *p_N; i++){
		*p = atoi(*(p_input + i));
		p++;
	}
}

void sort_array(int *p, int *p_N){
	//selection sort implementation
	int idx, tmp, i, j;
	for(int i = 0; i < *p_N; i++){
		idx = i;
		for(j = i + 1;j < *p_N; j++){
			if(*(p + j) < *(p + idx)){
				idx = j;
			}
		}
		if(idx != i){
			tmp = *(p + i);
			*(p + i) = *(p + idx);
			*(p + idx) = tmp;
		}
	}
}

void display_middle_two(int *p, int *p_N){
	//just print the two middle element
	printf("%d\n%d\n", *(p + (*(p_N) / 2 - 1)), *(p + (*(p_N) / 2)));
}

/*void display(int *p, int *p_N){
	for(int i = 0; i < *p_N; i++){
		printf("%d ", *p);
		p++;
	}
	printf("\n");
}*/
