/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;

        int n = 0;
        while(temp != NULL)
        {
            temp = temp -> next;
            n++;
        }

        if(n == 1)
            return {};
        if(n == 2)
        {
            head -> next = NULL;
            return head;
        }

        temp = head;
        while(fast != NULL && fast -> next != NULL)
        {
            temp = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        if(n % 2 == 0)
            temp -> next = slow -> next;
        else
            temp -> next = slow -> next;

        return head;
    }
};