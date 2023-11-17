/*
    author = Giuseppe Esposito;
    descrpition = we have a defalut list of number [8 7 3 4 5 6 9 2 14 12] to be stored in a linked list,
    The first argument is a member of the given list of numbers.
    The program find where the member is in the list, and place the second argument (an integer)
    after found member;
    date = 17/11/2023;
    approach =
    -we store the defalut list into a linked list
    -then with linear search, we try to find the node were node.value = second argument
    -if we find that node we insert the new one just after that one;
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
    int value;
    Node *next;
};

void push(Node **pHead, Node *pNewNode);//append an element to the linked list
Node* new_node(int n);//returns the address of a new node with value set to n
void print_ll(Node *p);//print the liked list
void default_input(Node **pHead);//store the default values in the liked list
void insert_at(Node **pHead, int key, int n);//insert a new node with value n after the node with value key

int main(int argc, char *argv[]){
    Node* head = NULL;

    default_input(&head);
    insert_at(&head, atoi(argv[1]), atoi(argv[2]));
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

void default_input(Node **pHead){
    int array[10] = {8,7,3,4,5,6,9,2,14,12};
    for(unsigned int i = 0; i < 10; i++){
        push(pHead, new_node(array[i]));
    }
}

void insert_at(Node **pHead, int key, int n){
    Node *curr = *pHead;
    Node *tmp = NULL;

    while(curr != NULL && curr->value != key){
        curr = curr->next;
    }
    if(curr != NULL){
        tmp = curr->next;
        curr->next = new_node(n);
        curr->next->next = tmp;
    }
}

