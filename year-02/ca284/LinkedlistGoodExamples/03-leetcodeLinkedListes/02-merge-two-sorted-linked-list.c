/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next
* };
*/
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){

    struct ListNode dummy;
    struct ListNode *node = &dummy;

    while(list1 != NULL && list2 != NULL){
        if(!list2 || (list1 != NULL && list1 -> val <= list2 -> val)){
            node -> next = list1;
            list1 = list1 -> next;
        }else{
            node -> next = list2;
            list2 = list2 -> next;
        }
            node = node -> next
    }

    return dummy.next;
}
