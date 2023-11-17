/*
    author = Giuseppe Esposito;
    description = store the number from the command line input in a liked list and print it;
    date = 17/11/2023
    approach =
    - we use a node struct
    - our likend list is a pointer to the first node
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
    int value;
    Node *next;
};

void print_LL(Node *p);//print the linked list
void Add_New_Node(Node **p_head, Node *newnode);//add a new node to the end of the linked list
Node* Create_New_Node(int val);//create a new node a return with value set to val and return its address
void fill_LL(Node **p_head, char **input, int size);//fill the linked list with the command line input

int main(int argc, char *argv[]){
    
    Node *head = NULL;

    fill_LL(&head, argv + 2, atoi(argv[1]));
    print_LL(head);

    return 0;
}

void print_LL(Node *p){
    while(p != NULL){
        printf("%d\n",p->value);
        p = p->next;
    }
}

void Add_New_Node(Node **p_head, Node *newnode){
    if(*p_head == NULL){
        *p_head = newnode;
    }else{
        Node *curr = *p_head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = newnode;
    }
}

Node* Create_New_Node(int val){
    Node *tmp = (Node*)malloc(1*sizeof(Node));
    tmp->value = val;
    tmp->next = NULL;
    return tmp;
}

void fill_LL(Node **p_head, char **input, int size){
    int N;
    for(unsigned int i = 0; i < size; i++){
        N = atoi(*(input + i)); 
        Add_New_Node(p_head, Create_New_Node(N));
    }
}
