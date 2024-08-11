class Solution {
public:
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int r, int c)
    {
        int n = grid.size();
        int m = grid[0].size();

        vis[r][c] = 1;
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for(int i = 0; i < 4; i++)
        {
            int nrow = r + dr[i];
            int ncol = c + dc[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                dfs(grid, vis, nrow, ncol);
        }
    }

    int countIsland(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    cnt++;
                    dfs(grid, vis, i, j);
                }
            }
        }

        return cnt;
    }

    int minDays(vector<vector<int>>& grid) {
        if(countIsland(grid) != 1) 
            return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    if(countIsland(grid) != 1)
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }
        
        return 2;
    }
};