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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, map<int, vector<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        vector<vector<int>> ans;
        
        if(root == NULL)
            return ans;
        
        q.push({root, {0, 0}});
        
        while(!q.empty())
        {
            pair<TreeNode*, pair<int, int>> temp = q.front();
            q.pop();
            
            TreeNode* node = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;
            
            nodes[hd][level].push_back(node -> val);
            
            if(node -> left)
                q.push({node -> left, {hd - 1, level + 1}});
            if(node -> right)
                q.push({node -> right, {hd + 1, level + 1}});
        }
        
        for(auto it : nodes)
        {
            vector<int> v;
            for(auto i : it.second)
            {
                sort(i.second.begin(), i.second.end());
                
                for(auto j : i.second)
                    v.push_back(j);
            }
            
            ans.push_back(v);
        }
        
        return ans;
    }
};