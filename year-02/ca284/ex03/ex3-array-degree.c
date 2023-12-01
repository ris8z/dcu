#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
    int value;
    int count;
    Node *next;
};

Node* add(Node *head, int n);
Node* new_node(int n);
void find_max_count(Node *head, int *max);
void display(Node *head);
void get_Input(Node **head, int len, char **input);

int main(int argc, char **argv){
    Node *head = NULL;
    int max_count = 0;
    
    get_Input(&head, argc - 1, argv + 1);
    find_max_count(head, &max_count);
    printf("%d\n", max_count);

    return 0;
}

Node* new_node(int n){
    Node* result = (Node*)malloc(sizeof(Node));
    if(!result)
        exit(0);
    result -> value = n;
    result -> count = 1;
    result -> next = NULL;
    return result;
}

Node* add(Node *head, int n){
    if(!head){
        return new_node(n);
    }

    Node *lastnode = head;
    Node *previous = NULL;

    while(lastnode != NULL && lastnode -> value != n){
        previous = lastnode;
        lastnode = lastnode -> next;
    }

    if(lastnode != NULL){
        lastnode -> count += 1;
        return head;
    }else{
        previous -> next = new_node(n);
    }
    
    return head;
}
void display(Node *head){
    if(head){
        printf("%d %d\n", head -> value, head -> count);
        display(head -> next);
    }
}
void find_max_count(Node *head, int *max){
    if(head){
        if(head -> count > *max)
            *max = head -> count;
        find_max_count(head -> next, max);
    }
}

void get_Input(Node **head, int len, char **input){
    for(int i = 0; i < len; i++){
        *head = add(*head, atoi(*(input + i)));
    }
}
