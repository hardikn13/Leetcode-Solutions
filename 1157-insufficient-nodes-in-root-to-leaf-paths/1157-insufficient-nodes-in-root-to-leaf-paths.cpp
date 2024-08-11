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
    bool f(int sum, TreeNode* root, int limit)
    {
        if(root -> left == NULL && root -> right == NULL)
        {
            sum += root -> val;

            if(sum < limit)
                return true;
            return false;
        }

        bool f1 = true, f2 = true;
        if(root -> left)
            f1 = f(sum + root -> val, root -> left, limit);
        if(root -> right)
            f2 = f(sum + root -> val, root -> right, limit);

        if(f1 && f2)
        {
            root -> left = NULL;
            root -> right = NULL;
            return true;
        }

        if(f1)
            root -> left = NULL;
        if(f2)
            root -> right = NULL;

        return false;
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        TreeNode* temp = NULL;
        if(root == NULL)
            return temp;
        if(f(0, root, limit))
            return temp;
        return root;
    }
};