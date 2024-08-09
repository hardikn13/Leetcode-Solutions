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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int stop = m * n;
        int num = 0;

        vector<vector<int>> ans(m, vector<int>(n, 0));
        int rowS = 0, rowE = m - 1, colS = 0, colE = n - 1;

        while(num != stop)
        {
            for(int i = colS; i <= colE && (num != stop); i++)
            {
                if(head != NULL)
                {
                    ans[rowS][i] = head -> val;
                    head = head -> next;
                }
                else
                    ans[rowS][i] = -1;

                num++;
            }
            rowS++;

            for(int i = rowS; i <= rowE && (num != stop); i++)
            {
                if(head != NULL)
                {
                    ans[i][colE] = head -> val;
                    head = head -> next;
                }
                else
                    ans[i][colE] = -1;

                num++;
            }
            colE--;

            for(int i = colE; i >= colS && (num != stop); i--)
            {
                if(head != NULL)
                {
                    ans[rowE][i] = head -> val;
                    head = head -> next;
                }
                else
                    ans[rowE][i] = -1;

                num++;
            }
            rowE--;

            for(int i = rowE; i >= rowS && (num != stop); i--)
            {
                if(head != NULL)
                {
                    ans[i][colS] = head -> val;
                    head = head -> next;
                }
                else
                    ans[i][colS] = -1;

                num++;
            }
            colS++;
        }

        return ans;
    }
};