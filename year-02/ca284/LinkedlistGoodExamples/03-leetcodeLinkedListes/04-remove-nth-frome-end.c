/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(head -> next == NULL){
        return NULL;
    }
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* slow = &dummy;
    struct ListNode* fast = head;

    while(n > 0){
        fast = fast -> next;
        n--;
    }

    while(fast){
        slow = slow -> next;
        fast = fast -> next;
        }

    slow -> next = slow -> next -> next;

    return dummy.next;
}
