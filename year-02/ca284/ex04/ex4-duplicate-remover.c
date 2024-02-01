#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
    int val;
    int count;
    Node* next;
};


void getInput(Node **head, char **input, int len);
Node* new_node(int N);
Node* push(Node *head, int N);
void display(Node *head);
Node* removeD(Node *head);

int main(int argc, char **argv){
    Node* head = NULL;

    getInput(&head, argv + 1, argc - 1);
    head = removeD(head);
    display(head);

    return 0;
}

Node* new_node(int N){
    Node* result = malloc(sizeof(Node));
    result -> val = N;
    result -> count = 1;
    result -> next = NULL;
    return result;
}

Node* push(Node *head, int N){
    if(!head)
        return new_node(N);

    Node* curr = head;
    Node* prev = NULL;
    while(curr != NULL && curr -> val != N){
        prev = curr;
        curr = curr -> next;
    }

    if(curr){
        curr -> count += 1;
    }else{
        prev -> next = new_node(N);
    }

    return head;
}

void display(Node *head){
    if(head){
        printf("%d\n", head -> val);
        //printf("%d %d\n", head -> val, head -> count);
        display(head -> next);
    }
}

void getInput(Node **head, char **input, int len){
    for(int i = 0; i < len; i++){
        *head = push(*head, atoi(*(input + i)));
    }
}

Node* removeD(Node *head){
    Node dummy;
    dummy.next = head;

    Node* curr = &dummy;
    while(curr && curr -> next){
        if(curr -> next -> count > 1){
            curr -> next = curr -> next -> next;
        }else{
            curr = curr -> next;
        }
    }

    return dummy.next;
}
