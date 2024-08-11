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
    int f(TreeNode* root, int par)
    {
        if(root == NULL)
            return 0;

        int ans = 0;
        if(root -> left || par == -1)
        {
            if(par % 2 == 0)
                ans += root -> left -> val + f(root -> left, root -> val);
            else
                ans += f(root -> left, root -> val);
        }

        if(root -> right || par == -1)
        {
            if(par % 2 == 0)
                ans += root -> right -> val + f(root -> right, root -> val);
            else
                ans += f(root -> right, root -> val);
        }
        
        return ans;
    }

    int sumEvenGrandparent(TreeNode* root) {
        return f(root, -1);
    }
};