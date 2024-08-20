class Solution {
public:
    int f(int node, int n, vector<int>& informTime, unordered_map<int, vector<int>> &adj)
    {
        int ans = 0;
        for(auto &it : adj[node])
            ans = max(ans, informTime[node] + f(it, n, informTime, adj));

        return ans;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < n; i++)
            adj[manager[i]].push_back(i);

        int ans = 0;
        for(auto &it : adj[headID])
            ans = max(ans, informTime[headID] + f(it, n, informTime, adj));

        return ans;
    }
};