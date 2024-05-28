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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int> ans;
        if(root == NULL)
            return ans;
        
        map<TreeNode*, TreeNode*> mp;
        queue<TreeNode*> q;
        
        q.push(root);
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            
            if(node -> left)
            {
                mp[node -> left] = node;
                q.push(node -> left);
            }
            
            if(node -> right)
            {
                mp[node -> right] = node;
                q.push(node -> right);
            }
        }
        
        queue<pair<TreeNode*, int>> q0;
        map<TreeNode*, bool> vis;
        
        q0.push({target, 0});
        vis[target] = true;
        
        while(!q0.empty())
        {
            int size = q0.size();
            int dist = q0.front().second;
            if(dist == k)
                break;
            
            for(int i = 0; i < size; i++)
            {
                auto spot = q0.front().first;
                int dist = q0.front().second;
                q0.pop();
                
                if(spot -> left && !vis[spot -> left])
                {
                    vis[spot -> left] = true;
                    q0.push({spot -> left, dist + 1});
                }
                
                if(spot -> right && !vis[spot -> right])
                {
                    vis[spot -> right] = true;
                    q0.push({spot -> right, dist + 1});
                }
                
                if(mp.find(spot) != mp.end() && !vis[mp[spot]])
                {
                    vis[mp[spot]] = true;
                    q0.push({mp[spot], dist + 1});
                }
            }
        }
        
        while(!q0.empty())
        {
            ans.push_back(q0.front().first -> val);
            q0.pop();
        }
        
        return ans;
    }
};