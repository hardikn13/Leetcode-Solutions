/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head){
struct ListNode* dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
struct ListNode* prev=dummy;
struct ListNode* curr=head;

    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    while(curr&&curr->next)
    {
        prev->next = curr->next;
        curr->next = prev->next->next;
        prev->next->next = curr;

        prev = curr;
        curr = curr->next;
    }
    return dummy->next;
}