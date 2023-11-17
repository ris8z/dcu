#include<stdio.h>
#include<stdlib.h>

//it returns the number of occurences of the value pointed by chr in the string pointed by string
int count_chr(char *chr, char *string);

int main(int argc, char *argv[])
{
	printf("%d\n", count_chr(argv[1], argv[2]));
	return 0;
}

int count_chr(char *chr, char *string){
	int result = 0;
	
	for(;*string;string++){
		if(*string == *chr){
		result++;
		}
	}

	return result;
}
