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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL)
            return head;

        ListNode* temp = head;
        int n = 1;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
            n++;
        }
        temp -> next = head;
        int t = n - (k % n);
        while(t != 0)
        {
            head = head -> next;
            t--;
        }
        temp = head;
        while(n - 1)
        {
            temp = temp -> next;
            n--;
        }
        temp -> next = NULL;
        return head;
    }
};