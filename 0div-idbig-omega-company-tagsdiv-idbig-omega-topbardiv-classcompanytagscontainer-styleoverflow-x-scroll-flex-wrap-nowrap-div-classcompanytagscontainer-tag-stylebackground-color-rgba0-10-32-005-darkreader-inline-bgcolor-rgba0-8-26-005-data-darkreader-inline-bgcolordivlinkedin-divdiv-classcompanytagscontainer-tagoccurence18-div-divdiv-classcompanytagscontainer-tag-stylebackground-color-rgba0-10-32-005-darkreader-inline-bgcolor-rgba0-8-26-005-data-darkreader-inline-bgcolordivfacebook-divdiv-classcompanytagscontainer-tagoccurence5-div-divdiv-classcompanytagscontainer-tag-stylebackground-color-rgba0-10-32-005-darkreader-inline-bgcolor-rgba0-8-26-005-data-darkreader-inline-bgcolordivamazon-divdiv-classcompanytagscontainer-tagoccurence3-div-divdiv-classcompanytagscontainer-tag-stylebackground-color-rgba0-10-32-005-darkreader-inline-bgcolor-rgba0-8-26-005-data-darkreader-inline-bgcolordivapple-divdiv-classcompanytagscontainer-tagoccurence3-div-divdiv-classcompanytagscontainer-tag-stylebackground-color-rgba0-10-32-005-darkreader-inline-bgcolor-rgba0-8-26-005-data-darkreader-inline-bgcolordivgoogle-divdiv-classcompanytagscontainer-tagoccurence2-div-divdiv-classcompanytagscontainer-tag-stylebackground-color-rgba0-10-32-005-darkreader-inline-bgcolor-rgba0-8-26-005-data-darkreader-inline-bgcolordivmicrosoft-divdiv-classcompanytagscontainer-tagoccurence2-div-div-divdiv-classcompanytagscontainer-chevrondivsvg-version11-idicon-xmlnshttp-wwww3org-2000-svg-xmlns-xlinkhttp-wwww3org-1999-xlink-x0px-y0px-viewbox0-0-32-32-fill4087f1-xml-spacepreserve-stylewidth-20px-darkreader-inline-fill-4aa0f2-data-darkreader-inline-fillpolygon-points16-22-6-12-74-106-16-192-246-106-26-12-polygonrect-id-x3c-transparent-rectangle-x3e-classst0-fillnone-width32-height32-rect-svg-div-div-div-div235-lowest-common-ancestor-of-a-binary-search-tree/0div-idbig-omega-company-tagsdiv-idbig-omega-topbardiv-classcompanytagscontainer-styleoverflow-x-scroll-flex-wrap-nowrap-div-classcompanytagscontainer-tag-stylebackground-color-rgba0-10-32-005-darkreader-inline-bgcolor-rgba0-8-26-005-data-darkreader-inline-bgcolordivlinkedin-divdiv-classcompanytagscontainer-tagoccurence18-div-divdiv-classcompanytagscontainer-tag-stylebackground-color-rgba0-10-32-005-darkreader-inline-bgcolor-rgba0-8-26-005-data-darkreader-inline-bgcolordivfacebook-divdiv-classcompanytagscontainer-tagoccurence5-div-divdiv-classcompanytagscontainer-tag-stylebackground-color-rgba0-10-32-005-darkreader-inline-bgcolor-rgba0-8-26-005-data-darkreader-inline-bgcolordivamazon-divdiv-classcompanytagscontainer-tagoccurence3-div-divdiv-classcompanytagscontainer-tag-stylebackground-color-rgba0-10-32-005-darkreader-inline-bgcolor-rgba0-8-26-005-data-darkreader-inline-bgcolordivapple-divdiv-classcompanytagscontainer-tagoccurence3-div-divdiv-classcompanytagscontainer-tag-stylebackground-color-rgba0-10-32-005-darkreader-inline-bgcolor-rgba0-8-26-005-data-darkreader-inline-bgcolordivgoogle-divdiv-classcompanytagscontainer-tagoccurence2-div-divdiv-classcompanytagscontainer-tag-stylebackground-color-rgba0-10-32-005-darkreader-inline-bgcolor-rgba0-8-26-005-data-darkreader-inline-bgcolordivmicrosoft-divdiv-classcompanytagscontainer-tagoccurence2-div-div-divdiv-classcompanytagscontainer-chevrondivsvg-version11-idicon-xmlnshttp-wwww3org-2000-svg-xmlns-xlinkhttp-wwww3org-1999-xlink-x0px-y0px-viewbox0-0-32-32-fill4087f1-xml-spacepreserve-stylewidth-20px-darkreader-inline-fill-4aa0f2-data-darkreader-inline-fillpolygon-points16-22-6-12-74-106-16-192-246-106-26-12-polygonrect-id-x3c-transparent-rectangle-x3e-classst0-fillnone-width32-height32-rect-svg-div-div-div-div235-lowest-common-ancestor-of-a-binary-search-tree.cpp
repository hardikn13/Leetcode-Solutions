/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL)
            return NULL;
        
        if(root -> val == p -> val || root -> val == q -> val)
            return root;
        
        while(root != NULL)
        {
            if(p -> val < root -> val)
            {
                if(q -> val >= root -> val)
                    return root;
                else
                    root = root -> left;
            }
            else
            {
                if(q -> val <= root -> val || p -> val == root -> val)
                    return root;
                else
                    root = root -> right;
            }
        }
        
        return root;
    }
};