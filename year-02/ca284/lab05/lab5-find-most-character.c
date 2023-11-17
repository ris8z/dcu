#include<stdio.h>
#include<stdlib.h>

//it returns the most frequent char in a string regardeless of being upper of lower case
char find_most_chr(char *string);

//it returns the index of the max element in and array of integers
int max_idx(int *arr, int N);

int main(int argc, char *argv[])
{
	printf("%c\n",find_most_chr(argv[1]));
	return 0;
}

char find_most_chr(char *string)
{
	/*the idea is that we have an array of 26 elment where
	0 is mapped to 'a', 1 to 'b' ,..., 25 to 'z'

	We go trough the string once if we find 'a' that is mapped with 0
	we incemente by one v[0]

	so we get the index of the position with the higher n with max_idx

	and we map that integer to his char adding + "a"
	*/
	int v[26] = {0};
	char key;
	char result;

	for(;*string;string++){
		if('a' <= *string && *string <= 'z'){
			key = 'a';
		}else{
			key = 'A';
		}
		v[*string - key] += 1;
	}
	result = max_idx(v, sizeof(v)/sizeof(v[0])) + 'a';

	return result;
}


int max_idx(int *arr, int N)
{
	int max_idx = 0;
	for(int i = 0; i < N; i++){
		if(*(arr + max_idx) < *(arr + i)){
			max_idx = i;
		}
	}

	return max_idx;
}
