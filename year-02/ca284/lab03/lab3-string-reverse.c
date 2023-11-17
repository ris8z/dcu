#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// swap char in idx1 and idx2 of an array
void swap(char array[], int idx1, int idx2);

int main(int argc, char *argv[])
{
	int N = strlen(argv[1]);
	int i = 0;
	int j = N - 1;

	while(i < j){
		swap(argv[1], i, j);
		i++;
		j--;
	};

	printf("%s\n", argv[1]);

	return 0;
}

void swap(char array[], int idx1, int idx2)
{
	char tmp = array[idx2];
	
	array[idx2] = array[idx1];
	array[idx1] = tmp;
}
