/*
    author = Giuseppe Esposito;
    description = store the numbers from command line in a double liked list and print the number backwards;
    date = 17/11/2023;
    approach:
    -we store two pointer(head, tail) one to holder the address 
    of the first node and the other one to hold the address of the last one
    -each node has two pointer(prec, next) one likes to the previus node the other the next one
    -we print each value starting from the tail and going by by useing the prec pointer

*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
    float value;
    Node *prec;
    Node *next;
};

void print_from_tail(Node *p);// print all the ll starting from the last node
Node *create_new_node(float n);// return the address of a new node with value set to n
void add_node(Node **pHead, Node **pTail, float val);// we append a new node to the ll
void fill_ll(Node **pHead, Node **pTail, char **input, int size);// we store the number from the input in the ll
//void print_from_head(Node *p); just for debug

int main(int argc, char *argv[]){
    Node* head = NULL;
    Node* tail = NULL;

    fill_ll(&head, &tail, argv + 2, atoi(argv[1]));
    print_from_tail(tail);

    return 0;
}


void print_from_tail(Node *p){
    while(p != NULL){
        printf("%.2f\n", p->value);
        p = p->prec;
    }
}

Node *create_new_node(float n){
    Node *tmp = NULL;
    tmp = (Node*)malloc(1*sizeof(Node));
    tmp->value = n;
    tmp->next = NULL;
    tmp->prec = NULL;
    return tmp;
}

void add_node(Node **pHead, Node **pTail, float val){
    Node *address_new_node = create_new_node(val);
    *pTail = address_new_node;
    if(*pHead == NULL){
        *pHead = address_new_node;
    }else{
        Node *curr = *pHead;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = address_new_node;
        address_new_node->prec = curr;
    }
}

void fill_ll(Node **pHead, Node **pTail, char **input, int size){
    float N;
    for(unsigned int i = 0; i < size; i++){
        N = atof(*(input + i));
        add_node(pHead, pTail, N);
    }
}

/*
void print_from_head(Node *p){
    while(p != NULL){
        printf("%.2f -> ", p->value);
        p = p->next;
    }
    printf("NULL\n");
}
*/






