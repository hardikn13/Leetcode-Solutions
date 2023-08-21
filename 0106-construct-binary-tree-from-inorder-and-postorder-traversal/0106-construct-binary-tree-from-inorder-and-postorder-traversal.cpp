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
    
    int findposition(vector<int>& inorder, int inorderstart, int inorderend, int element, int n)
    {
        for(int i = inorderstart; i <= inorderend; i++)
        {
            if(inorder[i] == element)
            {
                return i;
            }
        }
        return -1;
    }
    
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int &index, int inorderstart, int inorderend, int n)
    {
        if((index < 0) || (inorderstart > inorderend))
        {
            return NULL;
        }
        
        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        int position = findposition(inorder, inorderstart, inorderend, element, n);
        
        root -> right = solve(postorder, inorder, index, position + 1, inorderend, n);
        root -> left = solve(postorder, inorder, index, inorderstart, position - 1, n);
        
        return root;
        
    }

    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postorderindex = n - 1;
        TreeNode* ans = solve(postorder, inorder, postorderindex, 0, n - 1, n);
        return ans;
    }
};