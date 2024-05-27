class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto it : times)
            adj[it[0]].push_back({it[1], it[2]});
        
        vector<int> t(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({k, 0});
        t[k] = 0;
        
        while(!pq.empty())
        {
            int node = pq.top().first;
            int sec = pq.top().second;
            pq.pop();
                
            for(auto it : adj[node])
            {
                if(sec + it.second < t[it.first])
                {
                    t[it.first] = sec + it.second;
                    pq.push({it.first, t[it.first]});
                }
            }
        }
        
        int ans = INT_MIN;
        for(int i = 1; i <= n; i++)
        {
            if(t[i] == INT_MAX)
                return -1;
            
            ans = max(ans, t[i]);
        }
        
        return ans;
    }
};