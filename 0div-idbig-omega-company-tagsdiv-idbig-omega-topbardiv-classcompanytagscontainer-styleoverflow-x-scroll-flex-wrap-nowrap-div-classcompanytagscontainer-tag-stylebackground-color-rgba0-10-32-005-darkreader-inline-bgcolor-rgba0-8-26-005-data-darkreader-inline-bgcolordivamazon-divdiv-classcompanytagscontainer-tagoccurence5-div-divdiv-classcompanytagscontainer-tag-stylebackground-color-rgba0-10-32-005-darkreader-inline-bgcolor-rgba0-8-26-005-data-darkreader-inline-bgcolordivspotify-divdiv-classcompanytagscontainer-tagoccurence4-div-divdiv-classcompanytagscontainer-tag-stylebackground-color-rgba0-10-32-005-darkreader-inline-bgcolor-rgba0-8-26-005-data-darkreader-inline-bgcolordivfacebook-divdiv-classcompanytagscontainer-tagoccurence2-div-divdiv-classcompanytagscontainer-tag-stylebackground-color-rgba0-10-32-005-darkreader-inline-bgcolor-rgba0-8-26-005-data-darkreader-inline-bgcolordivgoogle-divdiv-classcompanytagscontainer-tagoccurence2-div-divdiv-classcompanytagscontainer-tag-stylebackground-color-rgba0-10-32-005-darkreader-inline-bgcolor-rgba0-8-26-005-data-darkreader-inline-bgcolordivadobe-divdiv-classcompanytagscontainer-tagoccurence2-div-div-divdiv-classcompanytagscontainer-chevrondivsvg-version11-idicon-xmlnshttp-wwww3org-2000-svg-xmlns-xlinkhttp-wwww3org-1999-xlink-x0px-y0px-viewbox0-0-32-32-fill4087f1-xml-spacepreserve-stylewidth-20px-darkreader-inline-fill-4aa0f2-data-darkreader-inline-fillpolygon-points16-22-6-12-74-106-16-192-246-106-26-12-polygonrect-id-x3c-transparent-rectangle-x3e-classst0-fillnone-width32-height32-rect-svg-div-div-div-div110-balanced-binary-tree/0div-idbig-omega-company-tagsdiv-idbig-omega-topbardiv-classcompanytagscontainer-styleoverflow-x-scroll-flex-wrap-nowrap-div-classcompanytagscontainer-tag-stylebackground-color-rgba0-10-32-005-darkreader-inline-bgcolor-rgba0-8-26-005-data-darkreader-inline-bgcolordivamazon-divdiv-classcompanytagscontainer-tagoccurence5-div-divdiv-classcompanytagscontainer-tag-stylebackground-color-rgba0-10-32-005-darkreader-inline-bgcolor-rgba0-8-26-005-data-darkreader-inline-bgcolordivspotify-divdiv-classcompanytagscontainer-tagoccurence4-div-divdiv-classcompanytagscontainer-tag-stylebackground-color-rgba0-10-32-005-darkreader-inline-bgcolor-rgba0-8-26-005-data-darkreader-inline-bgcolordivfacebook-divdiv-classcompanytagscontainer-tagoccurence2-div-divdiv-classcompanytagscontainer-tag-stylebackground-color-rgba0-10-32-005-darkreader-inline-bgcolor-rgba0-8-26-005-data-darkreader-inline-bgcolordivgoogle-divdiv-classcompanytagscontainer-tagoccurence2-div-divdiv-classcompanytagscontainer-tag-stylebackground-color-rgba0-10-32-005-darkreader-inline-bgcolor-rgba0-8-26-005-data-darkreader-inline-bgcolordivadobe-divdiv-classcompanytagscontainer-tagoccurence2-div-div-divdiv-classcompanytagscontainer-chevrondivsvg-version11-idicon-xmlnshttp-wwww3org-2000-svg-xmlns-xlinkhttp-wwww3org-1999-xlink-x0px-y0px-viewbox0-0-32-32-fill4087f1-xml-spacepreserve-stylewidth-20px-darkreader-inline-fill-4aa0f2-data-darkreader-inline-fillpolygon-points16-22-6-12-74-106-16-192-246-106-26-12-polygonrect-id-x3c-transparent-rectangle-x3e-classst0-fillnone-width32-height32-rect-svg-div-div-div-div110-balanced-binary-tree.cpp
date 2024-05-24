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
    int maxDepth(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        int lefty = maxDepth(root -> left);
        if(lefty == -1)
            return -1;
        int righty = maxDepth(root -> right);
        if(righty == -1)
            return -1;
        
        if(abs(lefty - righty) > 1)
            return -1;
        
        return 1 + max(lefty, righty);
    }
    
    bool isBalanced(TreeNode* root) {
        
        if(maxDepth(root) == -1)
            return false;
        
        return true;
    }
};