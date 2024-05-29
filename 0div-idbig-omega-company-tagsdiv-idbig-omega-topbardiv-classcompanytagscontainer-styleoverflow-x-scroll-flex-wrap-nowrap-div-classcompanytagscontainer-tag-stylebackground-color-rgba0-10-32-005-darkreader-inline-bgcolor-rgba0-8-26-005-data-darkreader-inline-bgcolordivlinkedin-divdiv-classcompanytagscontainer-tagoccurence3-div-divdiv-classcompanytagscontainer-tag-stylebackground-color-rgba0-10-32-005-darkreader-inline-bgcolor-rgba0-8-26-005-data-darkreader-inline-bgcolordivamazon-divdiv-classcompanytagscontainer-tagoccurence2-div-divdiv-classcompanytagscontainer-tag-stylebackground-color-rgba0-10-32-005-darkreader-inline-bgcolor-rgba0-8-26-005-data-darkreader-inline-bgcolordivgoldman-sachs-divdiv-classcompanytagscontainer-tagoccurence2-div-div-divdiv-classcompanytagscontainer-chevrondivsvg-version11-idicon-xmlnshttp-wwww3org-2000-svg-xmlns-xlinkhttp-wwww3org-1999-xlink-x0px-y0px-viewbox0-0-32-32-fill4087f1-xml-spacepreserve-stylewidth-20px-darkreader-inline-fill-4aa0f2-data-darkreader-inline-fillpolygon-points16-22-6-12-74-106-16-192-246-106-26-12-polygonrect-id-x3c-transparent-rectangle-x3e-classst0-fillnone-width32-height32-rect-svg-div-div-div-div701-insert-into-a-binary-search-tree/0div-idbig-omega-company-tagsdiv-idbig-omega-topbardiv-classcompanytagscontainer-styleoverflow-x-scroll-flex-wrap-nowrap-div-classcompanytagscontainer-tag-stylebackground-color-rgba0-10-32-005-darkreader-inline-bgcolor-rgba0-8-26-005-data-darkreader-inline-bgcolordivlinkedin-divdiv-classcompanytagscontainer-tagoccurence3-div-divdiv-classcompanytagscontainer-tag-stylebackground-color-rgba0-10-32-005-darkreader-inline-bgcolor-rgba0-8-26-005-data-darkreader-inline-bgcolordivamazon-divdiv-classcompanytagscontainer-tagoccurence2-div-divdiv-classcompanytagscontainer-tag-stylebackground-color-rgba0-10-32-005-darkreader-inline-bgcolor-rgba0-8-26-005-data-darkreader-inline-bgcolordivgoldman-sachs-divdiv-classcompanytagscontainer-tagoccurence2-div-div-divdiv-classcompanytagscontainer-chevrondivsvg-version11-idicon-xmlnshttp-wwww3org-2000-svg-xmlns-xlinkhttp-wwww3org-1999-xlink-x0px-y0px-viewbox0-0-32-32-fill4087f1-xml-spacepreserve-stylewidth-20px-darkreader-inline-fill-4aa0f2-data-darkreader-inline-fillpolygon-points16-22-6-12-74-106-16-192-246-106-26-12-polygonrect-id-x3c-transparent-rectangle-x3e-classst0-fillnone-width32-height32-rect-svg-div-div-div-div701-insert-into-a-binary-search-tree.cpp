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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode* curr = new TreeNode(val);
        if(root == NULL)
            return curr; 
        
        curr = root;
        while(curr)
        {
            if(val < curr -> val)
            {
                if(curr -> left)
                    curr = curr -> left;
                else
                {
                    TreeNode* next = new TreeNode(val);
                    curr -> left = next;
                    break;
                }
            }
            else
            {
                if(curr -> right)
                    curr = curr -> right;
                else
                {
                    TreeNode* next = new TreeNode(val);
                    curr -> right = next;
                    break;
                }
            }
        }
        
        return root;
    }
};