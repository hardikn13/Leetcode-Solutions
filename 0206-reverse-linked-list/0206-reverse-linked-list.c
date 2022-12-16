/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Reversing Elements
// -----------------
// struct ListNode* reverseList(struct ListNode* head){
// struct ListNode *p,*q;
//     p=head;
//     int *A,i=0,count=0;
//     while(q!=NULL)
//     {
//         q=q->next;
//         count++;
//     }
//     A=(int*)malloc(sizeof(int)*count);
//     while(q!=NULL)
//     {
//         A[i]=q->val;
//         q=q->next;
//         i++;
//     }
//     q=p;
//     i--;
//     while(q!=NULL)
//     {
//         q->val=A[i];
//         q=q->next;
//         i--;
//     }
// return A;
// }


// Reversing Links
// ---------------
// struct ListNode* reverseList(struct ListNode* head){
// struct ListNode *p,*q,*r;
//     p=head;
//     while(p!=NULL)
//     {
//         r=q;
//         q=p;
//         p=p->next;
//         q->next=r;
//     }
//     head=q;
//     return head;
// }


// Recursively
// -----------
struct ListNode* reverseList(struct ListNode* head){

    void reverse(struct ListNode*q, struct ListNode*p)
    {
        if(p!=NULL)
        {
            reverse(p,p->next);
            p->next=q;
        }
        else
        {
            head=q;
        }
    }
    reverse(NULL,head);
    return head;
}