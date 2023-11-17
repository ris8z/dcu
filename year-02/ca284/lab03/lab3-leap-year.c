#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool is_leap(int n);

int main(int argc, char *argv[])
{
	int year1 = atoi(argv[1]);
	int year2 = atoi(argv[2]);

	for(int i = year1; i <= year2; i++){
		if(is_leap(i)){
			printf("%d\n", i);
		}
	}

	return 0;
}

bool is_leap(int n){
	if(n % 4 != 0){
	return false;
	}

	if(n % 100 == 0 && n % 400 != 0){
	return false;
	}

	return true;	
}
