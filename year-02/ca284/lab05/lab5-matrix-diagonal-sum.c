#include<stdio.h>
#include<stdlib.h>

/*it updates the value of the var pointed by presult using data from the input
 argv through another pointer p*/
void matrix_diagonal_sum(int N, char **p, int *presult);

int main(int argc, char *argv[]){
	int result = 0;

 	matrix_diagonal_sum(atoi(argv[1]), argv + 2, &result);
	printf("%d\n", result);

	return 0;
}

/* we need to reach just the number that as the same col and rows
p points to the start of the block of memory that holds the numbers from the command line
we move of i cols by adding to p (i*N) where N is the dimesion of the matrix
and than we move to the same col by adding i
*(p + (i*N) + i) is the same as matrix[i][i] */
void matrix_diagonal_sum(int N, char **p, int *presult){
	for(int i = 0; i < N; i++)
		*presult += atoi(*(p + (i*N) + i));
}
