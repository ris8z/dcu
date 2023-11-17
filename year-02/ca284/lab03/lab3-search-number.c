#include<stdio.h>
#include<stdlib.h>

// returns the ind of q or -1
int linear_search(int a[], int len, int q);

int main(int argc, char *argv[])
{
	int query = atoi(argv[1]);
	int N = argc - 2;
	int array[50];
	int guess_index;
	
	//filling up the array
	for(int i = 0; i < N; i++){
		array[i] = atoi(argv[2 + i]);
	}
	
	//store the value of linear search in guess index
	guess_index = linear_search(array, N, query);

	if(guess_index != -1){
		printf("Found %d at %d\n", query, guess_index);
	}else{
		printf("%d not found\n", query);
	}

	return 0;
}


int linear_search(int a[], int len, int q)
{
	int idx = -1, i = 0;

	while(i < len && a[i] != q){
		i++;
	}

	if(i < len){
		idx = i;
	}
	
	return idx;
}
