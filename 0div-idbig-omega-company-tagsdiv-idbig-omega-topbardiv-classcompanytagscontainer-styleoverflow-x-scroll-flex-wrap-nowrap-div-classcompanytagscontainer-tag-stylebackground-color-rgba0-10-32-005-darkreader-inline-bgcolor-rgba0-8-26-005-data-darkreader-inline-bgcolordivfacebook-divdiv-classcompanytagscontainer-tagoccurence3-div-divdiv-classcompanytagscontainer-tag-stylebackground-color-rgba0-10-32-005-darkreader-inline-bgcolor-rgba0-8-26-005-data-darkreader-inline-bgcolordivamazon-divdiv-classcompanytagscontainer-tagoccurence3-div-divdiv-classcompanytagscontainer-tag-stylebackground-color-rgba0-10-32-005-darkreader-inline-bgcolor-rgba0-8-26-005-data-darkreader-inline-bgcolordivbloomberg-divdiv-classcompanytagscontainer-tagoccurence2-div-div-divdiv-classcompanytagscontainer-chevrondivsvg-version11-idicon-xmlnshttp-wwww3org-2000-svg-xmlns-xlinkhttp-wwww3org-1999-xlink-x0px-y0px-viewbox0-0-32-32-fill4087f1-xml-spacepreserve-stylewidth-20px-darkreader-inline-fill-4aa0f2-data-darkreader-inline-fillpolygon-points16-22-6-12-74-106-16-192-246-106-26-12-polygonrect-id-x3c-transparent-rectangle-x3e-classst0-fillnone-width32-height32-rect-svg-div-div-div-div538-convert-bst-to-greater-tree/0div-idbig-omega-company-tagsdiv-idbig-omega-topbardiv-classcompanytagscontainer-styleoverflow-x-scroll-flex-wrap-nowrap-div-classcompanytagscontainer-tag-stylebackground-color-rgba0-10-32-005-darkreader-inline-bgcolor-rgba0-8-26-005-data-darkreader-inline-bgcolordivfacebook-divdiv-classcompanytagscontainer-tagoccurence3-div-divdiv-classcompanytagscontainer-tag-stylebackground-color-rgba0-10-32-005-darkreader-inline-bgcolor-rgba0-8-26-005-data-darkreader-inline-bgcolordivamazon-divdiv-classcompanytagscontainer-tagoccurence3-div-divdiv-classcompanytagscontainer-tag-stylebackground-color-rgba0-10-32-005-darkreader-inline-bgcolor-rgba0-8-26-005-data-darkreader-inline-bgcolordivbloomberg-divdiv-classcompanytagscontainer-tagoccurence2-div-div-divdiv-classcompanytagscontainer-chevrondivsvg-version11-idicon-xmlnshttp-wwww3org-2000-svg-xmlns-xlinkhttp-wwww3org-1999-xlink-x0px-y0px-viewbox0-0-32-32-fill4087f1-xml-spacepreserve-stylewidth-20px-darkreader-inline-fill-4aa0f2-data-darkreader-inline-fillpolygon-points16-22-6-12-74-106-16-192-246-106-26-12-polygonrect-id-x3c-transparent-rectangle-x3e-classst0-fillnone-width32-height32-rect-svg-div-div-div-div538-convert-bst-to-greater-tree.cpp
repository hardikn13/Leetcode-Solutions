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
    void f(int &sum, TreeNode* root)
    {
        if(root == NULL)
            return;
        
        if(root -> right)
            f(sum, root -> right);
        
        sum += root -> val;
        root -> val = sum;
        
        if(root -> left)
            f(sum, root -> left);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL)
            return root;
        int sum = 0;
        f(sum, root);
        return root;
    }
};