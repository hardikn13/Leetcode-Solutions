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
    int f(TreeNode* root, int &cam)
    {
        if(root == NULL)
            return 1;
        
        int l = f(root -> left, cam);
        int r = f(root -> right, cam);
        
        if(l == 0 || r == 0)
        {
            cam++;
            return 2;
        }
        
        
        if(l == 2 || r == 2)
            return 1;
        
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        int cam = 0;
        if(f(root, cam) == 0)
            cam++;

        return cam;
    }
};