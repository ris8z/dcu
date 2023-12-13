#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
    int value;
    Node *next;
    Node *prec;
};

Node* new_node(int N);
Node* push(Node *head, int N);
Node* getTail(Node *head);
void llprintHead(Node *head);
void llprintTail(Node *tail);

int main(int argc, char **argv){
    Node* head = NULL;

    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);

    llprintHead(head);
    printf("-----------------\n");
    llprintTail(getTail(head));

    return 0;
}

Node* new_node(int N){
    Node *result = (Node*)malloc(sizeof(Node));

    if(!result)
        exit(0);

    result -> value = N;
    result -> next = NULL;
    result -> prec = NULL;
    return result;
}

Node* push(Node *head, int N){
    if(!head){
        return new_node(N);
    }else{
        Node *lastnode = head;
        while(lastnode->next != NULL){
            lastnode = lastnode->next;
        }
        lastnode -> next = new_node(N);
        lastnode -> next -> prec = lastnode;
    }

    return head;
}

Node* getTail(Node *head){
    while(head -> next != NULL){
        head = head -> next;
    }
    return head;
}

void llprintHead(Node *head){
    while(head != NULL){
        printf("%d\n", head -> value);
        head = head -> next;
    }
}

void llprintTail(Node *tail){
    while(tail != NULL){
        printf("%d\n", tail -> value);
        tail = tail -> prec;
    }
}
