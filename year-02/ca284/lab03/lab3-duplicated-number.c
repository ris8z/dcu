#include<stdio.h>
#include<stdlib.h>

void find_duplicate(int array[], int len);

int linear_search(int array[], int len, int query);

int main(int argc, char *argv[])
{
	int input_array[50];
	int N = argc - 1;

	for(int i = 0; i < N; i++){
		input_array[i] = atoi(argv[1 + i]);
	}

	find_duplicate(input_array, N);
	return 0;
}


void find_duplicate(int array[], int len)
{
	int seen[len];
	int k = 0;

	for(int i = 0; i < len; i++){
		if(linear_search(seen, k, array[i]) != -1){
			printf("%d\n", array[i]);
			break;
		}else{
			seen[k] = array[i];
			k++;
		}
	}

	if(k == len){
		printf("no duplicated number\n");
	}
	
}

int linear_search(int array[], int len, int query){
	int idx = -1;
	int i = 0;
	while(i < len && array[i] != query){
		i++;
	}

	if(i < len){
		idx = i;
	}

	return idx;
}
