#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	
	char mat[7][10] = {
		{"Sunday"},
		{"Monday"},
		{"Tuesday"},
		{"Wednesday"},
		{"Thursday"},
		{"Friday"},
		{"Saturday"}
	};
	int idx = atoi(argv[1]) - 1;


	printf("%s\n", mat[idx]);

	
	return (0);
}
