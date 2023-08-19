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
    
    void solve(TreeNode* root, int targetSum, unordered_map<long long, long long> &mp, int &count, long long prevSum)
    {
        if(root == NULL)
        {
            return;
        }
        long long currSum = root -> val + prevSum;
        if(mp.find(currSum - targetSum) != mp.end())
        {
            count += mp[currSum - targetSum];
        }
        if(currSum == targetSum)
        {
            count++;
        }
        
        mp[currSum]++;
        solve(root -> left, targetSum, mp, count, currSum);
        solve(root -> right, targetSum, mp, count, currSum);
        mp[currSum]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, long long> mp;
        int count = 0;
        solve(root, targetSum, mp, count, 0);
        return count;
    }
};