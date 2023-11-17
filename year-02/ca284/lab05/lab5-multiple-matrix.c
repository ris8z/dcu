#include<stdio.h>
#include<stdlib.h>

void mat(char **p1, char **p2, int r1, int c1, int r2, int c2);

int main(int argc, char *argv[]){
	int r1, c1, r2, c2;

	r1 = atoi(argv[1]);
	c1 = atoi(argv[2]);

	r2 = atoi(argv[2 + (r1 * c1) + 1]);
	c2 = atoi(argv[2 + (r1 * c1) + 2]);
	
	mat(argv + 3, argv + 3 + (r1 * c1) + 2, r1, c1, r2, c2);
	return 0;
}

void mat(char **p1, char **p2, int r1, int c1, int r2, int c2){
	int tmp;
	int array[r1*c2];
	int count = 0;

	for(int i = 0; i < r1; i++){
		for(int z = 0; z < c2; z++){
			tmp = 0;	
			for(int j = 0; j < c1; j++){
				tmp += atoi(*(p1 + (i * c1) + j)) * atoi(*(p2 + (j*c2) + z));
			}
			array[count] = tmp;
			count += 1;
		}
	}

	for(int i = 0; i < r1*c2 ; i++){
		printf("%d",array[i]);
		if((i + 1) % c2 == 0){
			printf("\n");
		}else{
			printf(" ");
		}
	}
}
