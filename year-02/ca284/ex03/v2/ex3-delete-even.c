#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;
typedef struct ll LL;

struct node{
    int val;
    Node* next;
    Node* prev;
};

struct ll{
    Node* left;
    Node* right;
};

LL* create();
Node* new_node(int n);
void display(LL* obj);
void push(LL* obj, int n);
void removeNode(Node* target);
void removeEven(LL *obj);
void getInput(LL* obj, char **input, int N);
int getsum(LL* obj);

int main(int argc, char **argv){
    LL* Mylist = create();

    getInput(Mylist, argv + 1, argc - 1);
    removeEven(Mylist);
    push(Mylist, getsum(Mylist));
    display(Mylist);

    return 0;
}

Node* new_node(int n){
    Node* result = malloc(sizeof(Node));
    if(!result)
        exit(0);
    result -> val = n;
    result -> next = NULL;
    result -> prev = NULL;
    return result;
}
LL* create(){
    LL *result = malloc(sizeof(LL));
    result -> left = new_node(0);
    result -> right = new_node(0);

    result -> left -> next = result -> right;
    result -> right -> prev = result -> left;
    return result;
}

void display(LL* obj){
    Node* curr = obj -> left -> next;
    while(curr != obj -> right){
        printf("%d\n", curr -> val);
        curr = curr -> next;
    }
}

void push(LL* obj, int n){
    Node* New = new_node(n);
    Node* before = obj -> right -> prev;
    Node* after = obj -> right;
    //we want to put New between before and after
    //before <-> New <-> after

    before -> next = New;
    New -> prev = before;
    
    New -> next = after;
    after -> prev = New;
}

void removeNode(Node* target){
    //our target we be a <-> target <-> b;
    Node* before = target -> prev;
    Node* after = target -> next;
    //we want before <-> after

    before -> next = after;
    after -> prev = before;
    free(target);
}

void getInput(LL* obj, char **input, int N){
    for(int i = 0; i < N; i++){
        push(obj, atoi(*(input + i)));
    }
}

void removeEven(LL *obj){
    Node *curr = obj -> left -> next;
    Node *linknext = NULL;
    while(curr != obj -> right){
        linknext = curr -> next;
        if(curr -> val % 2 == 0)
            removeNode(curr);
        curr = linknext;
    }
}

int getsum(LL* obj){
    Node *curr = obj -> left;
    int result = 0;
    while(curr != obj -> right){
        result += curr -> val;
        curr = curr -> next;
    }
    return result;
}
