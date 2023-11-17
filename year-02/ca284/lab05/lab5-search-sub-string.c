#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){
	char *sentence = argv[1];
	char *word = argv[2];
	char *p;
	
	p = strstr(sentence, word);

	if(p != NULL){
		printf("%d %d\n", p - sentence, p - sentence - 1 + strlen(word));
	}

	return 0;
}
