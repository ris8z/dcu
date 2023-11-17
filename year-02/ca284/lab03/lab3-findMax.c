#include<stdio.h>
#include<stdlib.h>

int max(int array[], int length);

int main(int argc, char *argv[])
{
	int N = argc - 1;
	int array[50];
	
	// filling up the array
	for(int i = 0; i < N; i++){
		array[i] = atoi(argv[1 + i]);
	}

	//print the max element
	printf("%d\n", max(array, N));

	return 0;
}

int max(int array[], int length)
{
	int res = array[0];

	for(int i = 0; i < length; i++){
		if(array[i] > res){
			res = array[i];
		}
	}
	return res;
}

