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
    vector<TreeNode*> f(int start, int end, map<pair<int, int>, vector<TreeNode*>> &dp)
    {
        if(start > end)
            return {NULL};

        if(start == end)
        {
            TreeNode* root = new TreeNode(start);
            return {root};
        }

        if(dp.find({start, end}) != dp.end())
            return dp[{start, end}];

        vector<TreeNode*> ans;

        for(int i = start; i <= end; i++)
        {
            vector<TreeNode*> left_BSTs = f(start, i - 1, dp);
            vector<TreeNode*> right_BSTs = f(i + 1, end, dp);

            for(auto it : left_BSTs)
            {
                for(auto t : right_BSTs)
                {
                    TreeNode* root = new TreeNode(i);
                    root -> left = it;
                    root -> right = t;

                    ans.push_back(root);
                }
            }
        }

        return dp[{start, end}] = ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> dp;
        return f(1, n, dp);
    }
};