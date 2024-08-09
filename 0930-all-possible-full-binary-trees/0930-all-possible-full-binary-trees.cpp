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
    vector<TreeNode*> f(int n, unordered_map<int, vector<TreeNode*>> &dp)
    {
        if(n % 2 == 0)
            return {};

        if(n == 1)
        {
            TreeNode* root = new TreeNode(0);
            return {root};
        }

        if(dp.find(n) != dp.end())
            return dp[n];

        vector<TreeNode*> ans;

        for(int i = 1; i < n; i += 2)
        {
            vector<TreeNode*> left_FBTs = f(i, dp);
            vector<TreeNode*> right_FBTs = f(n - i - 1, dp);

            for(auto &it : left_FBTs)
            {
                for(auto &t : right_FBTs)
                {
                    TreeNode* root = new TreeNode(0);
                    root -> left = it;
                    root -> right = t;

                    ans.push_back(root);
                }
            }
        }

        return dp[n] = ans;
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int, vector<TreeNode*>> dp;
        return f(n, dp);
    }
};