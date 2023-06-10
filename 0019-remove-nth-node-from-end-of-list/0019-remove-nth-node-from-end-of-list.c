/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
struct ListNode* p=head;
struct ListNode* q=head;
struct ListNode* r=head;
    if(head->next==NULL)
    {
        return NULL;
    }
    int count=0;
    while(r)
    {
        r=r->next;
        count++;
    }
    int start=count+1-n;
    if(start==1)
    {
        head=head->next;
    }
    for(int i=1;i<start;i++)
    {
        if(i==1)
        {
            p=p->next;
        }
        else
        {
            p=p->next;
            q=q->next;
        }
    }
    q->next=p->next;
    return head;
    
}
