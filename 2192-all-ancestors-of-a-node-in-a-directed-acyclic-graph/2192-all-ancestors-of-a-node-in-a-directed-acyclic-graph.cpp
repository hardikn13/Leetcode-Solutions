class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        vector<vector<int>> ans(n);
        
        vector<int> indegree(n, 0);
        for(auto it : edges)
        {
            indegree[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node])
            {
                for(auto i : ans[node]) {
                    if(find(ans[it].begin(), ans[it].end(), i) == ans[it].end()) {
                        ans[it].push_back(i);
                    }
                }
                
                if(find(ans[it].begin(), ans[it].end(), node) == ans[it].end()) {
                    ans[it].push_back(node);
                }
                
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        
        for(auto& it : ans)
            sort(it.begin(), it.end());
        
        return ans;
    }
};