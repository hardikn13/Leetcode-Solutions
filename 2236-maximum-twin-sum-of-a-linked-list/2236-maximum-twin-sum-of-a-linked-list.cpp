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
    int pairSum(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* temp = NULL;
        while(slow != NULL)
        {
            ListNode* pro = slow -> next;
            slow -> next = temp;
            temp = slow;

            if(pro == NULL)
                break;
            slow = pro;
        }

        int ans = INT_MIN;
        while(slow != NULL)
        {
            ans = max(ans, slow -> val + head -> val);
            slow = slow -> next;
            head = head -> next;
        }

        return ans;
    }
};