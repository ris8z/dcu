/*
    author = Giuseppe Esposito;
    descrpition = we get a list of number of size n(argv[1]) and another two number, we need to create a linked
    list with the first n number the pop two values from the end and append the other two number;
    date = 17/11/2023
    approach =
    -we store the pointer to the first node of the linked list
    -we append a new node with the push fuction
    -we remove an element with pop
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
    int value;
    Node *next;
};

void push(Node **pHead, Node *pNewNode);//append an element to the linked list
void pop(Node **pHead);//rome an element from the end of the linked list
Node* new_node(int n);//returns the address of a new node with value set to n
void print_ll(Node *p);//print the liked list
void fill_input(Node **pHead, char **input, int size, int *pl1, int *pl2);//store the input from command line

int main(int argc, char *argv[]){
    Node* head = NULL;
    int last_element1;
    int last_element2;

    fill_input(&head, argv + 2, atoi(argv[1]), &last_element1, &last_element2);
    pop(&head);
    pop(&head);
    push(&head, new_node(last_element1));
    push(&head, new_node(last_element2));
    print_ll(head);

    return 0;
}

void print_ll(Node *p){
    while(p != NULL){
        printf("%d\n", p->value);
        p = p->next;
    }
}

Node* new_node(int n){
    Node *tmp = (Node*)malloc(1*sizeof(Node));
    tmp->value = n;
    tmp->next = NULL;
    return tmp;
}

void push(Node **pHead, Node *pNewNode){
    if(*pHead == NULL){
        *pHead = pNewNode;
    }else{
        Node *curr = *pHead;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = pNewNode;
    }
}

void pop(Node **pHead){
    if(*pHead == NULL){
        return;
    }else if((*pHead)->next == NULL){
        free(*pHead);
        *pHead = NULL;
    }else{
        Node *curr = *pHead;
        while(curr->next->next != NULL){
            curr = curr->next;
        }
        free(curr->next);
        curr->next = NULL;
    }
}

void fill_input(Node **pHead, char **input, int size, int *pl1, int *pl2){
    int n;
    unsigned int i = 0;
    for(; i < size; i++){
        n = atoi(*(input + i));
        push(pHead, new_node(n));
    }
    *pl1 = atoi(*(input + i));
    *pl2 = atoi(*(input + i + 1));
}
