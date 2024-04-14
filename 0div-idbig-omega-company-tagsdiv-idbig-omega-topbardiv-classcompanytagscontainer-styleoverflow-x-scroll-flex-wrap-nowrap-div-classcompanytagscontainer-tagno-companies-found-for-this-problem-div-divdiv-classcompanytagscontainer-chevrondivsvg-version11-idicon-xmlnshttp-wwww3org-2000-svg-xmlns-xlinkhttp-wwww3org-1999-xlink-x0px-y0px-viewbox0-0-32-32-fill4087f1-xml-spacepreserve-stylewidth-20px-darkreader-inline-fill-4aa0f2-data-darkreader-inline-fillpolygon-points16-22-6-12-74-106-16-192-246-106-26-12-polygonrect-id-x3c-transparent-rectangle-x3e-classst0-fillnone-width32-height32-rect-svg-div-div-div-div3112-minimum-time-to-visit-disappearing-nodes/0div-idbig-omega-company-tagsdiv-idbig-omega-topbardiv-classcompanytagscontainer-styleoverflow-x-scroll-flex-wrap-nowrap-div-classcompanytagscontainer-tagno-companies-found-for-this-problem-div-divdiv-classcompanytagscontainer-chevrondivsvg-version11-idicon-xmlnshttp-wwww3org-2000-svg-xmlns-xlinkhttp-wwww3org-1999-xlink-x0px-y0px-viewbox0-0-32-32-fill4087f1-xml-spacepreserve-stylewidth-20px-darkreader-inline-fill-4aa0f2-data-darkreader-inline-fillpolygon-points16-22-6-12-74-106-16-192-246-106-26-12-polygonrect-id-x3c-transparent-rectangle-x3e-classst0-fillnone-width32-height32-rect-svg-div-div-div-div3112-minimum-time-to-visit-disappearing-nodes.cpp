class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        
        unordered_map<int, vector<pair<int, int>>> mp;
        
        for(auto it : edges)
        {
            mp[it[0]].push_back({it[1], it[2]});
            mp[it[1]].push_back({it[0], it[2]});
        }
        
        vector<int> ans(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        
        while (!pq.empty())
        {
            auto [time, node] = pq.top();
            pq.pop();
            
            if (ans[node] != -1) continue;
            
            ans[node] = time;
            
            for (auto& neighbor : mp[node])
            {
                int nextNode = neighbor.first;
                int edgeTime = neighbor.second;
                
                if (time + edgeTime < disappear[nextNode] && ans[nextNode] == -1) {
                    pq.push({time + edgeTime, nextNode});
                }
            }
        }
        
        return ans;
    }
};