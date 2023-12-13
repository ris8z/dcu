/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head);
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2, int c);

void reorderList(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast && fast->next){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    struct ListNode* rightHead = slow -> next;
    slow -> next = NULL;
    rightHead = reverseList(rightHead);
    merge(head, rightHead, 0);
}

struct ListNode* reverseList(struct ListNode* head){
    	if(!head || !(head -> next)){
            return head;
        }
        struct ListNode *node = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;

        return node;
}

void display(struct ListNode* head){
    if(head){
        printf("%d -> ", head -> val);
        display(head -> next);
    }else{
        printf("NULL\n");
    }
}

struct ListNode* merge(struct ListNode* l1, struct ListNode* l2, int c){
    if(!l1){
        return l2;
    }
    if(!l2){
        return l1;
    }

    struct ListNode* head = NULL;
    if(c % 2 == 0){
        head = l1;
        l1 = l1 -> next;
    }else{
        head = l2;
        l2 = l2 -> next;
    }

    head -> next = merge(l1, l2, c + 1);

    return head;
}
