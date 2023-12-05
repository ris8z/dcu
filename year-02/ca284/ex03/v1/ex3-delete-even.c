#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
    int data;
    Node *next;
    Node *prec;
};

Node* new_node(int n);
Node* push(Node *head, int n);
void display(Node *head);
Node* remove_node(Node *head, Node *target);
void remove_even(Node **head);
int sum(Node *head);
void getInput(Node **head, int len, char **input);

int main(int argc, char **argv){
    Node *head = NULL;

    getInput(&head, argc - 1, argv + 1);
    remove_even(&head);
    head = push(head, sum(head));
    display(head);

    return 0;
}

Node* new_node(int n){
    Node *tmp = (Node*)malloc(sizeof(Node));
    if(!tmp)
        exit(0);
    tmp -> data = n;
    tmp -> next = NULL;
    tmp -> prec = NULL;
    return tmp;
}

Node* push(Node *head, int n){
    if(!head){
        return new_node(n);
    }

    head -> next = push(head -> next, n);
    head -> next -> prec = head;

    return head;
}

void display(Node *head){
    if(head){
        printf("%d\n", head -> data);
        display(head -> next);
    }
}

Node* remove_node(Node *head, Node *target){
    if(head == target){
        Node *tmp = head;
        head -> next -> prec = NULL;
        head = head -> next;
        free(tmp);
        return head;
    }
    Node *tmp = target;
    target -> prec -> next = target -> next;
    if(target -> next != NULL)
        target -> next -> prec = target -> prec;
    free(tmp);

    return head;
}

void remove_even(Node **head){
    Node *curr = *head;
    Node *tmp = NULL;
    while(curr != NULL){
        tmp = curr -> next;
        if(curr -> data % 2 == 0){
            *head = remove_node(*head, curr);
        }
        curr = tmp;
    }
}

int sum(Node *head){
    Node *curr = head;
    int result = 0;
    while(curr != NULL){
        result += curr -> data;
        curr = curr -> next;
    }
    return result;
}

void getInput(Node **head, int len, char **input){
    for(int i = 0; i < len; i++){
        *head = push(*head, atoi(*(input + i)));
    }
}
