class Solution {
public:
    bool bfs(int i, vector<int> adj[], vector<int>& color)
    {
        queue<int> q;
        q.push(i);
        color[i] = 0;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node])
            {
                if(color[it] == -1)
                {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node])
                    return false;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        int m = graph[0].size();
        vector<int> color(n, -1);
        
        vector<int> adj[n];
        for(int i = 0; i < n; i++)
        {
            for(int j : graph[i])
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
        
        for(int i = 0 ; i < n; i++)
        {
            if(color[i] == -1)
            {
                if(bfs(i, adj, color) == false)
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};