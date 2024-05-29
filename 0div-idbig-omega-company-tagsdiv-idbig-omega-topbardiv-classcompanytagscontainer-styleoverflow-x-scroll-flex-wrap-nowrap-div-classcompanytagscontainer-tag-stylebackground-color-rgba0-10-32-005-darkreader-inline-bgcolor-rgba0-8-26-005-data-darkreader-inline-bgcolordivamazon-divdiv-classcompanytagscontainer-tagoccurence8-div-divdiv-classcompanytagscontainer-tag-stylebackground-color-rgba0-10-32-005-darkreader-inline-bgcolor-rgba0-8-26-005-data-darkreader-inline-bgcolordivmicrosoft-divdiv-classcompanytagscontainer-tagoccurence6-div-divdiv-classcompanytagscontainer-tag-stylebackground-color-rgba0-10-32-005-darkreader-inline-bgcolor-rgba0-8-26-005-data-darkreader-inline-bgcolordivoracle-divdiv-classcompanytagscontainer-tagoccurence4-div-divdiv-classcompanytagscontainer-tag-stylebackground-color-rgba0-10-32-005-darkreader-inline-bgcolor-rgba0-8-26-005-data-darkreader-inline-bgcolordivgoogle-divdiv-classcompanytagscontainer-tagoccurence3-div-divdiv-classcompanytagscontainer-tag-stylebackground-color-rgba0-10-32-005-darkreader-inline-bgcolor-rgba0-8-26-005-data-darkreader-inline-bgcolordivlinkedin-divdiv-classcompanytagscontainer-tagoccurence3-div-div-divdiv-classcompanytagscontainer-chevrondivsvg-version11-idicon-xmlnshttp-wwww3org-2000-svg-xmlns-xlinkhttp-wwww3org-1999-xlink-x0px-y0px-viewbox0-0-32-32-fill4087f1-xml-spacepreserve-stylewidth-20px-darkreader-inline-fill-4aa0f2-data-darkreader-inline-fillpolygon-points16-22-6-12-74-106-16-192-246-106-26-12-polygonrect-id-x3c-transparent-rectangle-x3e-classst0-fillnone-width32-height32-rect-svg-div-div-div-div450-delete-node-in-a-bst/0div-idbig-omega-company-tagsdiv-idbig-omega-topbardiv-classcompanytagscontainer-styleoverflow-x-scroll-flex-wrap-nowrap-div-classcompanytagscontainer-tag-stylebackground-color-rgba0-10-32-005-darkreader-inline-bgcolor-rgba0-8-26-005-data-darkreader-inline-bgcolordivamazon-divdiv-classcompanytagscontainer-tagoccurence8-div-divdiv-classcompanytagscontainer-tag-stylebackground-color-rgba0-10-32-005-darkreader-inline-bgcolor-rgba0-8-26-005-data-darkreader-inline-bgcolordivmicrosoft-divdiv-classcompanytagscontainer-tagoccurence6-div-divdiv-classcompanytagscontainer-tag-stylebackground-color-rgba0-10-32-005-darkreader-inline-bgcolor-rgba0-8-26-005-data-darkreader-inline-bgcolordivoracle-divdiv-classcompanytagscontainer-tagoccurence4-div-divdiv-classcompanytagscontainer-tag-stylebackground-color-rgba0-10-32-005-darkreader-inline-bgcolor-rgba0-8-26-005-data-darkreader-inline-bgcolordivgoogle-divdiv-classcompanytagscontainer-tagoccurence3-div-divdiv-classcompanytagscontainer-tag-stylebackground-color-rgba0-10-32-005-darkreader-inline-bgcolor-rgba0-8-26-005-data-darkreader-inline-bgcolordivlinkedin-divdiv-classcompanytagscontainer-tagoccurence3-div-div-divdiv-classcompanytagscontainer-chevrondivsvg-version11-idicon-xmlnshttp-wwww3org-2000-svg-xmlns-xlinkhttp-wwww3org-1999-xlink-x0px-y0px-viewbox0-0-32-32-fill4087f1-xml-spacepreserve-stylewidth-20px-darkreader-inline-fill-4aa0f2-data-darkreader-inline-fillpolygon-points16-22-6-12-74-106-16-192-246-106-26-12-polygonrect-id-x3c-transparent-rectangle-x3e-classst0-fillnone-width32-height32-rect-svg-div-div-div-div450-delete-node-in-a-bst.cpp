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
    TreeNode* f(TreeNode* root)
    {
        if(root -> left == NULL)
            return root -> right;
        
        if(root -> right == NULL)
            return root -> left;
        
        TreeNode* rightChild = root -> right;
        TreeNode* lastRight = findLastRight(root -> left);
        lastRight -> right = rightChild;
        
        return root -> left;
    }
    
    TreeNode* findLastRight(TreeNode* root)
    {
        while(root -> right != NULL)
            root = root -> right;
            
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == NULL)
            return NULL;
        
        if(root -> val == key)
            return f(root);
        
        TreeNode* curr = root;
        while(curr != NULL)
        {
            if(key < curr -> val)
            {
                if(curr -> left && curr -> left -> val == key)
                {
                    curr -> left = f(curr -> left);
                    break;
                }
                else
                    curr = curr -> left;
            }
            else
            {
                if(curr -> right && curr -> right -> val == key)
                {
                    curr -> right = f(curr -> right);
                    break;
                }
                else
                    curr = curr -> right;
            }
        }
        
        return root;
    }
};