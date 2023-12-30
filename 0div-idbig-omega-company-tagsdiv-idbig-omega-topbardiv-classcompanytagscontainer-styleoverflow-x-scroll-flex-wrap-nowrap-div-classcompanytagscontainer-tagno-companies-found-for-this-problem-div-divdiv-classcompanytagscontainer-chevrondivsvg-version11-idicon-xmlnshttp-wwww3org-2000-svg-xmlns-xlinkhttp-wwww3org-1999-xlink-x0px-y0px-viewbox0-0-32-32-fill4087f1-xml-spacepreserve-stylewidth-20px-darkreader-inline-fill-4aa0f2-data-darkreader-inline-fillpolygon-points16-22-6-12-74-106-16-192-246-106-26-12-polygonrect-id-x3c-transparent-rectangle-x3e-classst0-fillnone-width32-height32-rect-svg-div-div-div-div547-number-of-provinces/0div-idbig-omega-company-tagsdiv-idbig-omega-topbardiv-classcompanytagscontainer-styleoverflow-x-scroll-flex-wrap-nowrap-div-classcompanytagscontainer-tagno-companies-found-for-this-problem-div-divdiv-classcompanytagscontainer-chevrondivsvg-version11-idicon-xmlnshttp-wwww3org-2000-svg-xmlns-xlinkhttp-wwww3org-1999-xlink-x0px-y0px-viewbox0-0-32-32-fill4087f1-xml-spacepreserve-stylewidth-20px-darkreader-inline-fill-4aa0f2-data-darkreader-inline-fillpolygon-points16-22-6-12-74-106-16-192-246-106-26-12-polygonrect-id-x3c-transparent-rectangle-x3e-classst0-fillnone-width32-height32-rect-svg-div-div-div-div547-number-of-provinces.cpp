class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>> adjList)
    {
        vis[node] = 1;
        
        for(auto it : adjList[node])
        {
            if(!vis[it])
            {
                dfs(it, vis, adjList);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size(), ans = 0;
        vector<int> vis(n, 0);
        
        vector<vector<int>> adjList(n);
        for(int i = 0; i < n; i++)
        {
		    for(int j = 0; j < n; j++)
            {
			    if(isConnected[i][j] == 1)
				    adjList[i].push_back(j);
		    }
	    }
        
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(i, vis, adjList);
            }
        }
        
        return ans;
    }
};