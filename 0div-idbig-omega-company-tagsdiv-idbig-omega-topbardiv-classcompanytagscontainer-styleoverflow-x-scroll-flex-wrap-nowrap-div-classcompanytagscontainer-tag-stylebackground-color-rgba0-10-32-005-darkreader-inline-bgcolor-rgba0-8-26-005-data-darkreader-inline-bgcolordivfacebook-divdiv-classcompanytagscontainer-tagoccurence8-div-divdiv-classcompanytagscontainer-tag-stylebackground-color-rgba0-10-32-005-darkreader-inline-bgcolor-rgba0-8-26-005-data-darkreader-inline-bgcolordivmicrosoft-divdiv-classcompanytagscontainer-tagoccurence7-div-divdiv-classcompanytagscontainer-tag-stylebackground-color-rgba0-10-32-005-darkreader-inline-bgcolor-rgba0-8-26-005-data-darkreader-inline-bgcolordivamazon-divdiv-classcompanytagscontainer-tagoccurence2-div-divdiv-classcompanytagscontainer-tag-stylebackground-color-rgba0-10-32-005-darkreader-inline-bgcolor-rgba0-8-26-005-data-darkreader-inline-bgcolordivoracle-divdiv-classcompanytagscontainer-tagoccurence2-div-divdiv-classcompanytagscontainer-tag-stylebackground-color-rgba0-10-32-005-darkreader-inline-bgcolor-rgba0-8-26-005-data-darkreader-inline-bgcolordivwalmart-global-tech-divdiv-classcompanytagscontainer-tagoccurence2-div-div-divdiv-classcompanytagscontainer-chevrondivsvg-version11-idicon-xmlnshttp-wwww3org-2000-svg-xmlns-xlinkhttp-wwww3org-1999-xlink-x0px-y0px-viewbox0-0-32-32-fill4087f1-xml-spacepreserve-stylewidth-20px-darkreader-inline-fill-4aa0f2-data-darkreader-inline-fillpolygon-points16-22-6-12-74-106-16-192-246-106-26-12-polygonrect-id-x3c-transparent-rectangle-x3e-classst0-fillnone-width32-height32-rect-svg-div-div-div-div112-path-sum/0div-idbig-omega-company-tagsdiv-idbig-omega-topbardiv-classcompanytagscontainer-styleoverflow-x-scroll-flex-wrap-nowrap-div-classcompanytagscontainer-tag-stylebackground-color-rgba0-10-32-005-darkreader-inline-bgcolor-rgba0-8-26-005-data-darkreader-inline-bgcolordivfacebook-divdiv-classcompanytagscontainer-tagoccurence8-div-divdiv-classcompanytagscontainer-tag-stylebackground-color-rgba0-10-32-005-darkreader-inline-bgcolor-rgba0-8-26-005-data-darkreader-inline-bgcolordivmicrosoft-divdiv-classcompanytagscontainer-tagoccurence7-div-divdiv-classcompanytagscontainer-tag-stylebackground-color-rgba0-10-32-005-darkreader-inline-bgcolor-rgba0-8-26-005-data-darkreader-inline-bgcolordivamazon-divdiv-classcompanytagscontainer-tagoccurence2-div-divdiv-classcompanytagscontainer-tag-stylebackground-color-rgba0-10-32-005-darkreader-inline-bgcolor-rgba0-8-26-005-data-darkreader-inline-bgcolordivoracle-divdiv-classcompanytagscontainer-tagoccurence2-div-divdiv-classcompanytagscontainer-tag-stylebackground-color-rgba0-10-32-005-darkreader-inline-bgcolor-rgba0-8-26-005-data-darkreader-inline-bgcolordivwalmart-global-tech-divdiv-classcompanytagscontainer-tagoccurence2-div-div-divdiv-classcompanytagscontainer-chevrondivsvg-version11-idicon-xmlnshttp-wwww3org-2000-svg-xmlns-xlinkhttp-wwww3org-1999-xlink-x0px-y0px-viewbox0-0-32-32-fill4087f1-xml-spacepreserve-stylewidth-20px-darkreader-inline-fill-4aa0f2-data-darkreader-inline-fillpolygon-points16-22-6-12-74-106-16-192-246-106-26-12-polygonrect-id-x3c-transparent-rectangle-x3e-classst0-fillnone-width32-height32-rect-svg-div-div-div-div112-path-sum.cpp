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
    bool f(TreeNode* root, int sum, int targetSum)
    {
        if(root -> left == NULL && root -> right == NULL)
        {
            sum += root -> val;
            
            if(sum == targetSum)
                return true;
            
            return false;
        }
        
        return (root->left && f(root -> left, sum + root -> val, targetSum)) ||
           (root->right && f(root -> right, sum + root -> val, targetSum));
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root == NULL)
            return false;
        
        int sum = 0;
        return f(root, sum, targetSum);
    }
};