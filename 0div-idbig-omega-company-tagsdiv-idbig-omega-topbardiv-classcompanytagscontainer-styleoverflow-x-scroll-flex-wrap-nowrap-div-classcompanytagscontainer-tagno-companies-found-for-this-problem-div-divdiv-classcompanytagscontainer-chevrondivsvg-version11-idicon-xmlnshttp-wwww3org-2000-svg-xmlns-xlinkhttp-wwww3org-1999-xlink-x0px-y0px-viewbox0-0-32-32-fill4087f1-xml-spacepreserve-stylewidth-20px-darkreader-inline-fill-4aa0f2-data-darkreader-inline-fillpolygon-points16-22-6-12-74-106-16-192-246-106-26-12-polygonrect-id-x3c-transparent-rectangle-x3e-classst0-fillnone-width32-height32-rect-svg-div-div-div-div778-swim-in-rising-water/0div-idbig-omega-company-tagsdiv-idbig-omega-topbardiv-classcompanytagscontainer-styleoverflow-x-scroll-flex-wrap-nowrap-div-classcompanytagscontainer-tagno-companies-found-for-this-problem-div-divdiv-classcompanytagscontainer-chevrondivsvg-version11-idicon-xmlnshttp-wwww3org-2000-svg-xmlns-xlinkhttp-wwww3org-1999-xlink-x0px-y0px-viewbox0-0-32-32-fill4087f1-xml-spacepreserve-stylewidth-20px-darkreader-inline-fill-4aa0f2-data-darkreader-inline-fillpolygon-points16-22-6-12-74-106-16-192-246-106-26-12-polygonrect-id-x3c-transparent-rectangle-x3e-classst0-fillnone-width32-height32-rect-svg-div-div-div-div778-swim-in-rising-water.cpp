class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;
        
        int ans = INT_MAX;
        while(!pq.empty())
        {
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int old = time;
            pq.pop();
            
            if(row == n - 1 && col == n - 1)
                ans = min(ans, time);
            
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};
            for(int i = 0; i < 4; i++)
            {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                time = old;
                
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && !vis[nRow][nCol])
                {
                    if(grid[nRow][nCol] <= time)
                    {
                        vis[nRow][nCol] = 1;
                        pq.push({time, {nRow, nCol}});
                    }
                    else
                    {
                        time = grid[nRow][nCol];
                        vis[nRow][nCol] = 1;
                        pq.push({time, {nRow, nCol}});
                    }
                }
            }
        }
        
        return ans;
    }
};