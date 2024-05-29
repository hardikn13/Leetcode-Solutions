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
    TreeNode* buildTree(vector<int> preorder, int &ind, int bound)
    {
        if(ind == preorder.size() || preorder[ind] > bound)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[ind++]);
        
        root -> left = buildTree(preorder, ind, root -> val);
        root -> right = buildTree(preorder, ind, bound);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind = 0;
        return buildTree(preorder, ind, INT_MAX);
    }
};