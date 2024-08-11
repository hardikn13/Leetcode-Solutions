class Solution {
public:
    int f(int node, int par, int &ans, vector<vector<int>> &adj)
    {
        int sum = 0;
        unordered_set<int> st;

        for(auto &it : adj[node])
        {
            if(it == par)
                continue;

            int ct = f(it, node, ans, adj);
            sum += ct;
            st.insert(ct);
        }

        if(st.size() <= 1)
            ans++;
        
        return sum + 1;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for(auto &it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int ans = 0;
        f(0, -1, ans, adj);
        return ans;
    }
};