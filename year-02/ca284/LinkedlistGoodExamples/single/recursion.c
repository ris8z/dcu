#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
    int data;
    Node *next;
};

Node* new_node(int value);
Node* push(Node *head, int value);
void llprint(Node *head);

int main(int argc, char **argv){
    Node *head = NULL;

    head = push(head, 12);
    head = push(head, 13);
    head = push(head, 15);

    llprint(head);
    return 0;
}

Node* new_node(int value){
    Node *result = (Node*)malloc(sizeof(Node));

    if(!result)
        exit(0);

    result -> data = value;
    result -> next = NULL;
    return result;
}

Node* push(Node *head, int value){
    if(!head){
        return new_node(value);
    }

    head -> next = push(head -> next, value);

    return head;
}

void llprint(Node *head){
    if(head){
        printf("%d\n", head -> data);
        llprint(head -> next);
    }
}
