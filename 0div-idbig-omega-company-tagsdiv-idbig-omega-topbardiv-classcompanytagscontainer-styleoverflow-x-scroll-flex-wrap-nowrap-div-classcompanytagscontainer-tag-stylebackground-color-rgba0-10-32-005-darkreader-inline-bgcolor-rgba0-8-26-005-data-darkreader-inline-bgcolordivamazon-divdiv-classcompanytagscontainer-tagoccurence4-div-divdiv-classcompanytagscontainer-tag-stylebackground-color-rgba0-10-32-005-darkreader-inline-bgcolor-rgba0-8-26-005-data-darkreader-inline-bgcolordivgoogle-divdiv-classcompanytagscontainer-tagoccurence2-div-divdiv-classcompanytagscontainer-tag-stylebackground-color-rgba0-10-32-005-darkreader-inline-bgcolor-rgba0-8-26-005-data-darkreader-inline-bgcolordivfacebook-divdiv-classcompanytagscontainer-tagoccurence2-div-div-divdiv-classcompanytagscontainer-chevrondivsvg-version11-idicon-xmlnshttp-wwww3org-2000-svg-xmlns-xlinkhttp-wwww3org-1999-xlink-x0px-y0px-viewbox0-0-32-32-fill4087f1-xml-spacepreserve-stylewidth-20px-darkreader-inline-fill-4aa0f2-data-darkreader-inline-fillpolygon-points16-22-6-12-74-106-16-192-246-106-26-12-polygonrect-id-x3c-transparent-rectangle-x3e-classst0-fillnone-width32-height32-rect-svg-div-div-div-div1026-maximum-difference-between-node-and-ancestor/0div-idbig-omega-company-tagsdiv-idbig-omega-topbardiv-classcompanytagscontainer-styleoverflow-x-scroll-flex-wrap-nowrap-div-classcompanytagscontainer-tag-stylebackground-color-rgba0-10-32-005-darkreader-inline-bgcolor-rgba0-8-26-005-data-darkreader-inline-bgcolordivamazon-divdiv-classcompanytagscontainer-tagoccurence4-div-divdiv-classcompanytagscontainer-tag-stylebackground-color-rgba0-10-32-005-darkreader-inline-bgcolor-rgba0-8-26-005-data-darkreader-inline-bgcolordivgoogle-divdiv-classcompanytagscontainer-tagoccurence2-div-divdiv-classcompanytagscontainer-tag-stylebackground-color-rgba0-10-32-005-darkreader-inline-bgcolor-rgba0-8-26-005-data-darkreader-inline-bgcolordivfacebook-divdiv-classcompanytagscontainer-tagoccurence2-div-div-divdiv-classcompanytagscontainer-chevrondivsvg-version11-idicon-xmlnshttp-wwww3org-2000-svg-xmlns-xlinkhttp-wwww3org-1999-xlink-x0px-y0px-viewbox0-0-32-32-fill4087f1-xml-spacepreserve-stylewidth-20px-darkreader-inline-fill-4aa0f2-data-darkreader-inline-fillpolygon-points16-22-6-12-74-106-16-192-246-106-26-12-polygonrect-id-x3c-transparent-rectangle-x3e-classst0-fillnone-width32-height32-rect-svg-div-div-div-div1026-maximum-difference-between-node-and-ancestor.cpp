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
    int recur(TreeNode* root, int maxi,int mini){
        if(!root) return maxi-mini;
        int nmini=mini,nmaxi=maxi;

        int l=recur(root->left, max(root->val,maxi),min(root->val,mini));
        int r=recur(root->right, max(root->val,maxi),min(root->val,mini));
        return max(l,r);

    }


    int maxAncestorDiff(TreeNode* root) {

        return recur(root,root->val,root->val);
    }
};