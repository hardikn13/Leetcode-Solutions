class Solution {
public:
    vector<int> topo(vector<vector<int>>& edges, int n)
    {
        vector<vector<int>> adj(n + 1);
        vector<int> indegree(n + 1, 0);
        queue<int> q;

        for(auto it : edges)
        {
            indegree[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }

        int count = 0;
        for(int i = 1; i <= n; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                count++;
            }
        }

        vector<int> order;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            order.push_back(node);
            for(auto &it : adj[node])
            {
                indegree[it]--;

                if(indegree[it] == 0)
                {
                    q.push(it);
                    count++;
                }
            }
        }

        if(count != n)
            return {};

        return order;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<int> row = topo(rowConditions, k);
        vector<int> col = topo(colConditions, k);

        if(row.empty() || col.empty())
            return {};

        vector<vector<int>> ans(k, vector<int>(k, 0));
        for(int i = 0; i < k; i++)
            for(int j = 0; j < k; j++)
                if(row[i] == col[j])
                    ans[i][j] = col[j];

        return ans;
    }
};