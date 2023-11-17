#include<stdio.h>
#include<stdlib.h>

void swap(int a[], int idx1, int idx2);
int idx_min(int a[], int idx1, int idx2);
void selection_sort(int a[], int len);

int main(int argc, char *argv[]){
	
	int N = argc - 1;
	int array[50];

	//fill the array
	for(int i = 0; i < N; i++){
		array[i] = atoi(argv[1 + i]);
	}

	selection_sort(array, N);

	//print the array
	for(int i = 0; i < N; i++){
		printf("%d\n",array[i]);
	}

	return 0;
}


void swap(int a[],int idx1, int idx2)
{
	int tmp = a[idx1];
	a[idx1] = a[idx2];
	a[idx2] = tmp;
}

int idx_min(int a[], int idx1, int idx2)
{
	int min = a[idx1];
	int index = idx1;

	for(int i = idx1; i < idx2 + 1; i++){
		if(a[i] < min){
			min = a[i];
			index = i;
		}	
	}
	return index;
}


void selection_sort(int a[], int len)
{
	int index;

	for(int i = 0; i < len; i++){
		index = idx_min(a, i, len - 1);
		swap(a, i, index); 		
	}
}
