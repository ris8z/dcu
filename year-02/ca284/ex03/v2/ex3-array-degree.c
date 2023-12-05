#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
    int val;
    int count;
    Node* next;
};

Node* new_node(int n);
Node* push(Node* head, int n);
void display(Node* head);
void getInput(Node** head, char **input, int N);
int getMaxDegree(Node* head);

int main(int argc, char **argv){
    Node* head = NULL;

    getInput(&head, argv + 1, argc - 1);
    printf("%d\n", getMaxDegree(head));

    return 0;
}

Node* new_node(int n){
    Node* tmp = malloc(sizeof(Node));
    if(!tmp)
        exit(0);
    tmp -> val = n;
    tmp -> count = 1;
    tmp -> next = NULL;
}

Node* push(Node* head, int n){
    if(!head){
        return new_node(n);
    }

    Node* curr = head;
    Node* prev = NULL;
    while(curr && curr -> val != n){
        prev = curr;
        curr = curr -> next;
    }

    if(curr){
        curr -> count += 1;
    }else{
        prev -> next = new_node(n);
    }

    return head;
}

void display(Node* head){
    if(head){
        printf("%d %d\n", head -> val, head -> count);
        display(head -> next);
    }
}

void getInput(Node** head, char **input, int N){
    for(int i = 0; i < N; i++){
        *head = push(*head, atoi(*(input + i)));
    }
}

int getMaxDegree(Node* head){
    Node* curr = head;
    int max = 0;
    while(curr){
        if(curr -> count > max)
            max = curr -> count;
        curr = curr -> next;
    }
    return max;
}
