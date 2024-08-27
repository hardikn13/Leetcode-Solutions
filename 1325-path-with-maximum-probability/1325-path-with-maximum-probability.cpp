class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<double> dis(n, 0);
        priority_queue<pair<double, int>> pq;
        pq.push({1.00, start_node});
        dis[start_node] = 1;

        while(!pq.empty())
        {
            auto prob = pq.top().first;
            auto node = pq.top().second;
            pq.pop();

            if(node == end_node)
                return dis[end_node];

            for(auto &it : adj[node])
            {
                if(dis[it.first] < prob * it.second)
                {
                    dis[it.first] = prob * it.second;
                    pq.push({dis[it.first], it.first});
                }
            }
        }

        return 0;
    }
};