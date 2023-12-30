class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0, cntFresh = 0;
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        
        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < m; col++)
            {
                if(grid[row][col] == 2)
                {
                    vis[row][col] = 2;
                    q.push({{row, col}, 0});
                }
                
                if(grid[row][col] == 1)
                {
                    cntFresh++;
                }
            }
        }
        
        int time = 0;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();
            
            
            
            for(int i = 0; i < 4; i++)
            {
                int nRow = r + delRow[i];
                int nCol = c + delCol[i];
                
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                  grid[nRow][nCol] == 1 && vis[nRow][nCol] != 2)
                {
                    vis[nRow][nCol] = 2;
                    q.push({{nRow, nCol}, t + 1});
                    cnt++;
                }
            }
        }
        
        if(cnt != cntFresh)
            return -1;
        
        return time;
    }
};