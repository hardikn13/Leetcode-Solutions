/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty())
        {
            auto node = q.front().first;
            auto cur = q.front().second;
            q.pop();

            cur = cur * 10 + node -> val;

            if(node -> left)
                q.push({node -> left, cur});      
            if(node -> right)
                q.push({node -> right, cur});

            if(!node -> left && !node -> right)
                sum += cur;
        }

        return sum;
    }
};