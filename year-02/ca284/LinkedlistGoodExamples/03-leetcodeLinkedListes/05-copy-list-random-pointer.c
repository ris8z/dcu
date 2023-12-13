/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */
typedef struct Node Node;
struct Node* copyRandomList(struct Node* head) {
    if(!head)
        return NULL;
    
    //insert each new node after the origianl one
    Node* curr = head;
    while(curr){
        //create a new node
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node -> val = curr -> val;

        //the next node after the new must be the next original node
        new_node -> next = curr -> next;
        //the next node after the origian(current) must be the new
        curr -> next = new_node;

        //move curr to the next origianl node
        curr = curr -> next -> next;
    }

    //add the random node for each new node
    curr = head;
    Node* new_node = NULL;
    while(curr){
        //the new node is the next node to the original node
        new_node = curr -> next;

        if(curr -> random){
            new_node -> random = curr -> random -> next;
        }else{
            new_node -> random = NULL;
        }
        //move the curr to next orignal node
        curr = curr -> next -> next;
    }

    //split the original list from the new list
    Node* originalList = head;
    Node* copiedList = head -> next;
    Node* copiedListHead = head -> next;
    while(originalList){
        originalList -> next = originalList -> next -> next;
        if(copiedList -> next){
            copiedList -> next = copiedList -> next -> next;
        }else{
            copiedList -> next = NULL;
        }
        originalList = originalList -> next;
        copiedList = copiedList -> next;
    }

    return copiedListHead;
}
