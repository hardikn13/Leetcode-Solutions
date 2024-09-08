class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        int len = 0;
        ListNode* temp = head;
        
        while (temp != NULL)
        {
            temp = temp -> next;
            len++;
        }

        int per = len / k;
        int extra = len % k;
        
        vector<ListNode*> ans(k, NULL);
        int i = 0;

        while(head != NULL)
        {
            ans[i++] = head;
            int sz = per + (extra-- > 0 ? 1 : 0);

            for(int j = 1; j < sz && head != NULL; j++)
                head = head -> next;

            if(head != NULL)
            {
                ListNode* nextHead = head -> next;
                head -> next = NULL;
                head = nextHead;
            }
        }

        return ans;
    }
};
