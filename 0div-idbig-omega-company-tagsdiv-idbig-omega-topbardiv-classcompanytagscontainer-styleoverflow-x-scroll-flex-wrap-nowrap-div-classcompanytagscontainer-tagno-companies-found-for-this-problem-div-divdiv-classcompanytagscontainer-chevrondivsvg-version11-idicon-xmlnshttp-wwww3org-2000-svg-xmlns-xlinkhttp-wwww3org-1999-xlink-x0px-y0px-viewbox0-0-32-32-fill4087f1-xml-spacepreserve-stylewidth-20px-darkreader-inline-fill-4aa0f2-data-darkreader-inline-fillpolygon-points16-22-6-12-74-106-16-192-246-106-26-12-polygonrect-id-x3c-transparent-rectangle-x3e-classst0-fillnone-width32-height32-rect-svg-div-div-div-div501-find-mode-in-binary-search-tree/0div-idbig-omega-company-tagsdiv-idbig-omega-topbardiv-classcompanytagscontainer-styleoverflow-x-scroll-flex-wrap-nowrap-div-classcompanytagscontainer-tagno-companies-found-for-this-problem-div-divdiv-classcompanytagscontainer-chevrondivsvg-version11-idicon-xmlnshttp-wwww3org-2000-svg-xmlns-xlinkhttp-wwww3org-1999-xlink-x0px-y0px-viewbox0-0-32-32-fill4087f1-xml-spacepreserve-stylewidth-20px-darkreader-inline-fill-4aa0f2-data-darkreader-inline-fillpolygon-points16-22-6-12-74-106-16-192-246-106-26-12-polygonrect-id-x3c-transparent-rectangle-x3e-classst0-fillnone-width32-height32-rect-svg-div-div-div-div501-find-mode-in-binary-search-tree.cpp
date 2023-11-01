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
    
    void f(TreeNode* root, unordered_map<int, int> &mp)
    {
        if(root == NULL)
            return;
        
        mp[root -> val]++;
        f(root -> left, mp);
        f(root -> right, mp);
    }
    
    vector<int> findMode(TreeNode* root) {
        
        vector<int> ans;
        unordered_map<int, int> mp;
        
        f(root, mp);
        
        int maxF = 0;
        
        for(auto it : mp)
        {
            if(it.second > maxF)
                maxF = it.second;
        }
        
        for(auto it : mp)
        {
            if(it.second == maxF)
                ans.push_back(it.first);
        }
        
        return ans;
    }
};