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
    void f(TreeNode* root, int &depth, int temp)
    {
        if(root == NULL)
            return;
        
        depth = max(depth, temp);
        f(root -> left, depth, temp + 1);
        f(root -> right, depth, temp + 1);
    }
    
    TreeNode* ff(TreeNode* root, int temp, int depth)
    {
        if(root == NULL)
            return root;
        
        if(temp == depth)
            return root;
        
        TreeNode* lefty = ff(root -> left, temp + 1, depth);
        TreeNode* righty = ff(root -> right, temp + 1, depth);
        
        if(lefty != NULL && righty != NULL)
            return root;
        
        return lefty != NULL ? lefty : righty;
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root == NULL)
            return NULL;
        
        int depth = 0;
        f(root, depth, 0);
        
        return ff(root, 0, depth);
    }
};