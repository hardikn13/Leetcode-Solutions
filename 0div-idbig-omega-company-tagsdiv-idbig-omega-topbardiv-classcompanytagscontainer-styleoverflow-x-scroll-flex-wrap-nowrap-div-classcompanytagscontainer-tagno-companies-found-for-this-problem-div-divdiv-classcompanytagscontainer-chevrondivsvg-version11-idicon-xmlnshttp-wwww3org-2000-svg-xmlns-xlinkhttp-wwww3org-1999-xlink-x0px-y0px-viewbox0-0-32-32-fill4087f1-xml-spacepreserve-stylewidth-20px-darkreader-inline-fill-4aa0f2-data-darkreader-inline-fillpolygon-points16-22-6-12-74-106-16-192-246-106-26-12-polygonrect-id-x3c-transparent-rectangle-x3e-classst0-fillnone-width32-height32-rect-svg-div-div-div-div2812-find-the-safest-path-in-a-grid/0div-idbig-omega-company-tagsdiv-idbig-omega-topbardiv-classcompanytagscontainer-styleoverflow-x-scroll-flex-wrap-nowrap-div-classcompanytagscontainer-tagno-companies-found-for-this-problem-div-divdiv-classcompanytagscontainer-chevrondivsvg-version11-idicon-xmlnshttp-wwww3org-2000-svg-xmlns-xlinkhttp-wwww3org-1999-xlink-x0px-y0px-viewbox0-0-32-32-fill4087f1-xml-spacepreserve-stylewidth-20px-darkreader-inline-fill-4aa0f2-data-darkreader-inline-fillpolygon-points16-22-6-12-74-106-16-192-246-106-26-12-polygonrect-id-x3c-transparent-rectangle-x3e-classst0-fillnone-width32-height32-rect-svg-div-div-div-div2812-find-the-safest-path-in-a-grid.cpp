class Solution {
public:
    
    int n, m;
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};
    
    bool checkSteps(vector<vector<int>> &distance, int mid)
    {
        queue<pair<int, int>> q0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        q0.push({0, 0});
        visited[0][0] = 1;
        
        if(distance[0][0] < mid)
            return false;
        
        while(!q0.empty())
        {
            int r = q0.front().first;
            int c = q0.front().second;
            q0.pop();
            
            if(r == n - 1 && c == m - 1)
                return true;
            
            for(int i = 0; i < 4; i++)
            {
                int nROW = r + delRow[i];
                int nCOL = c + delCol[i];
                
                if(nROW >= 0 && nROW < n && nCOL >= 0 && nCOL < m && !visited[nROW][nCOL])
                {
                    if(distance[nROW][nCOL] < mid)
                        continue;
                    
                    visited[nROW][nCOL] = 1;
                    q0.push({nROW, nCOL});
                }
            }
        }
        
        return false;
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> distance(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                }
            }
        }
        
        int maxStep = 0;
        
        while(!q.empty())
        {
            int steps = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            distance[row][col] = steps;
            
            for(int i = 0; i < 4; i++)
            {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && grid[nRow][nCol] == 0)
                {
                    vis[nRow][nCol] = 1;
                    maxStep = max(maxStep, steps + 1);
                    q.push({steps + 1, {nRow, nCol}});
                }
            }
        }
        
        int ans = 0;
        int low = 0, high = maxStep + 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            
            if(checkSteps(distance, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        
        return ans;
    }
};