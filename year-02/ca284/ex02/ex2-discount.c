/*
	author: Giuseppe Esposito;
	description: this program prints the total price of the items in a Cart 
	date: 02/11/2023;
	approach:
	-we modle the input from the command line as items in a cart
	-then we just add the prices of the items according if there is a sale or not
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Item Item;

struct Item{
	char name[20];
	int amount;
	float price;
	int sale;

};

void fill_the_cart(Item *p, int *p_N, char **p_input);
float total(Item *p, int *p_N);

int main(int argc, char *argv[]){
	Item Cart[100];
	int N = argc / 4;

	fill_the_cart(Cart, &N, argv + 1);
	printf("%.2f\n",total(Cart, &N));

	return 0;
}


void fill_the_cart(Item *p, int *p_N, char **p_input){
	//here we use 3 pointer to fill the Cart array using data from argv matrix
	for(int i = 0; i < *p_N; i++){
		strcpy(p->name, *(p_input + (i * 4)));
		p->amount = atoi(*(p_input + (i * 4) + 1));
		p->price = atof(*(p_input + (i * 4) + 2));
		p->sale = atoi(*(p_input + (i * 4) + 3));
		p++;
	}
}

float total(Item *p, int *p_N){
	/*n and pr are two tmp variables to hold the amount number and the price to
	improve readabilty;

	for each item in the cart we add to the total price amount * price
	but if an item is On sale, we subtract the money that the client don't have
	to pay:
	
	that is the interger division between the amount and 3 times the price of the item
	*/
	float result = 0;
	int n;
	float pr;
	for(int i = 0; i < *p_N; i++){
		n = p->amount;
		pr = p->price;
		result += n * pr;
		if(p->sale == 1)
			result -= (((n - (n % 3)) / 3) * pr);
		p++;
	}
	return result;
}
