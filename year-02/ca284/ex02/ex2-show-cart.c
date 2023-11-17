/*
	author: Giuseppe Esposito;
	description: the goal is to display the items of a cart that we take from
	the command line input;
	date: 02/11/2023;
	approach:
	-we define a struct Item e we consider an array of item as a Cart
	-we just save the input from the command line
	-and then we display it with right format
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Item Item;

struct Item{
	char name[20];
	int amount;
	float price;
	char sale[8];

};

void fill_the_cart(Item *p, int *p_N, char **p_input);
void display(Item *p, int *p_N);

int main(int argc, char *argv[]){
	//a cart is an array of item
	Item Cart[100];
	int N = argc / 4;

	
	fill_the_cart(Cart, &N, argv + 1);
	display(Cart, &N);

	return 0;
}


void fill_the_cart(Item *p, int *p_N, char **p_input){
	//here we use three pointer to fill the Cart array using data from argv matrix
	for(int i = 0; i < *p_N; i++){
		strcpy(p->name, *(p_input + (i * 4)));
		p->amount = atoi(*(p_input + (i * 4) + 1));
		p->price = atof(*(p_input + (i * 4) + 2));
		if(atoi(*(p_input + (i * 4) + 3)) == 1){
			strcpy(p->sale,"On Sale");
		}else{
			strcpy(p->sale,"No Sale");
		}
		p++;
	}
}

void display(Item *p, int *p_N){
	//here we simply print the data stored before
	for(int i = 0; i < *p_N; i++){
		printf("%s,%d,%.2f,%s\n",p->name,p->amount,p->price,p->sale);
		p++;
	}
}
