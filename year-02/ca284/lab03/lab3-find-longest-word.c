#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//we use this to find the two point i and k that are the start and the end of the longest word
void find_twoindex(char sentence[], int N);

//we use this to print that word, by printing each char from i to k
void p_frm_to(char str[], int idx1, int idx2);

int main(int argc, char *argv[])
{
	int N = strlen(argv[1]);
	char sentence[N];
	strcpy(sentence, argv[1]);
	
	find_twoindex(sentence, N);
	
	return 0;
}


void find_twoindex(char sentence[], int N)
{
	int idx1, idx2;
	int maxlen = 0;
	int i = 0, k;

	while(i < N){
		k = i + 1;
		//we move k until we find the end of a word
		while(('a' <= sentence[k] && sentence[k] <= 'z') || ('A' <= sentence[k] && sentence[k] <= 'Z')){
			k += 1;
		}
		//we check if the distance between k and i is the longest found
		if(k - i > maxlen){
			maxlen = k - i;
			idx1 = i;
			idx2 = k;
		}
		
		i = k + 1;
		//we move i until we find the start of a word
		while(!(('a' <= sentence[i] && sentence[i] <= 'z') || ('A' <= sentence[i] && sentence[i] <= 'Z'))){
			i += 1;
		}
	}
	//we print the longest word	
	p_frm_to(sentence, idx1, idx2);
}


void p_frm_to(char str[], int idx1, int idx2)
{
	for(int i = idx1; i < idx2; i++){
		printf("%c", str[i]);
	}
	printf("\n");
}
