class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int n = targetGrid.size();
        int m = targetGrid[0].size();

        unordered_map<int, vector<int>> row, col;
        unordered_set<int> st;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                st.insert(targetGrid[i][j]);

        for(auto &it : st)
        {
            int minX = max(n, m), minY = max(n, m);
            int maxX = 0, maxY = 0;

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(targetGrid[i][j] == it)
                    {
                        maxX = max(maxX, j);
                        minX = min(minX, j);
                        maxY = max(maxY, i);
                        minY = min(minY, i);
                    }
                }
            }

            row[it].push_back(minY);
            row[it].push_back(maxY);
            col[it].push_back(minX);
            col[it].push_back(maxX);
        }

        vector<vector<int>> adj(61);
        vector<int> indegree(61, 0);
        for(auto &it : st)
        {
            int minR = row[it][0], maxR = row[it][1], minC = col[it][0], maxC = col[it][1];
            
            set<int> set;
            for(int i = minR; i <= maxR; i++)
            {
                for(int j = minC; j <= maxC; j++)
                {
                    if(it != targetGrid[i][j])
                        set.insert(targetGrid[i][j]);
                }
            }

            indegree[it] += set.size();
            for(auto &t : set)
                adj[t].push_back(it);
        }

        int cnt = 0;
        queue<int> q;
        for(int i = 1; i <= 61; i++)
        {
            if(st.find(i) != st.end() && indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            cnt++;
            for(auto &it : adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }

        if(cnt == st.size())
            return true;
        return false;
    }
};