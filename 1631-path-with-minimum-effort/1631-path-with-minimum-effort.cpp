class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            if(r == n - 1 && c == m - 1)
            {
                return diff;
            }
            
            for(int i = 0; i < 4; i++)
            {
                int nRow = r + delRow[i];
                int nCol = c + delCol[i];
                
                if(nRow < n && nRow >= 0 && nCol < m && nCol >= 0)
                {
                    int newEffort = max(abs(heights[r][c] - heights[nRow][nCol]), diff);
                    
                    if(newEffort < dist[nRow][nCol])
                    {
                        dist[nRow][nCol] = newEffort;
                        pq.push({dist[nRow][nCol], {nRow, nCol}});
                    }
                    
                }
            }
        }
        return -1;
    }
};