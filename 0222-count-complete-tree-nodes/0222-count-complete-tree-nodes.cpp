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
    
    int inorder(TreeNode* root, int count)
    {
        if(root == NULL)
        {
            return count;
        }
        
        count++;
        count = inorder(root->left, count);
        count = inorder(root->right, count);
        return count;
    }
    
    
    int countNodes(TreeNode* root) {
        return inorder(root, 0);
    }
};