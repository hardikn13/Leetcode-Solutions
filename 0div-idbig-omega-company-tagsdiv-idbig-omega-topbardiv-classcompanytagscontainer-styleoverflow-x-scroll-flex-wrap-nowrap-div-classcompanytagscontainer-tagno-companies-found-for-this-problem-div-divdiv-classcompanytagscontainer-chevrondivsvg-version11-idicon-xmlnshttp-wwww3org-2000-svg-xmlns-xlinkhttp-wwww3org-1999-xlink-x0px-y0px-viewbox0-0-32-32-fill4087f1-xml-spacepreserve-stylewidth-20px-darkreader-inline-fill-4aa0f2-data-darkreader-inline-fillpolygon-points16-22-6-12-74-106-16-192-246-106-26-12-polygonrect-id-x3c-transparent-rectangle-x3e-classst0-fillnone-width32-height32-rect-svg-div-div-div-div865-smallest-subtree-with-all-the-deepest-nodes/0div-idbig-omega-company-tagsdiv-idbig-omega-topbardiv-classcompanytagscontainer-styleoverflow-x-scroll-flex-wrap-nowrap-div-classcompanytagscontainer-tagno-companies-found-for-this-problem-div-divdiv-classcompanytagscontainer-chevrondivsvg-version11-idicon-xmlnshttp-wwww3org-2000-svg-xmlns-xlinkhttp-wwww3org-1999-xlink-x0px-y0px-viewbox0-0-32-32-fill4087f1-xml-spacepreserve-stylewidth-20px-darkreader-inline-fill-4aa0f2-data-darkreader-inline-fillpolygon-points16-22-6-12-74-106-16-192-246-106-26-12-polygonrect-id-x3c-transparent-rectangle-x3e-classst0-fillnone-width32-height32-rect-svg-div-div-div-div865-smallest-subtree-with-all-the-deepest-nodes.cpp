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
    pair<TreeNode*, int> f(TreeNode* root)
    {
        if(root == NULL)
            return {NULL, 0};
        
        auto left = f(root->left);
        auto right = f(root->right);
        
        if(left.second == right.second)
            return {root, left.second + 1};
        else if (left.second > right.second)
            return {left.first, left.second + 1};
        else
            return {right.first, right.second + 1};
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return f(root).first;
    }
};