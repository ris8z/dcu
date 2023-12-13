/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* NewNode(int n){
    struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
    tmp -> val = n;
    tmp -> next = NULL;
    return tmp;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = NULL;
    struct ListNode* curr = NULL;

    int sum = 0;
    int carry = 0;
    while(l1 || l2){
        sum = carry;
        if(l1)
            sum += l1 -> val;
        if(l2)
            sum += l2 -> val;

        carry = sum / 10;
        sum = sum % 10;

        if(!head){
            head = NewNode(sum);
            curr = head;
        }else{
            curr -> next = NewNode(sum);
            curr = curr -> next;
        }

        if(l1)
            l1 = l1 -> next;
        if(l2)
            l2 = l2 -> next;

    }

    if(carry != 0){
        curr -> next = NewNode(carry);
    }
    return head;
}
