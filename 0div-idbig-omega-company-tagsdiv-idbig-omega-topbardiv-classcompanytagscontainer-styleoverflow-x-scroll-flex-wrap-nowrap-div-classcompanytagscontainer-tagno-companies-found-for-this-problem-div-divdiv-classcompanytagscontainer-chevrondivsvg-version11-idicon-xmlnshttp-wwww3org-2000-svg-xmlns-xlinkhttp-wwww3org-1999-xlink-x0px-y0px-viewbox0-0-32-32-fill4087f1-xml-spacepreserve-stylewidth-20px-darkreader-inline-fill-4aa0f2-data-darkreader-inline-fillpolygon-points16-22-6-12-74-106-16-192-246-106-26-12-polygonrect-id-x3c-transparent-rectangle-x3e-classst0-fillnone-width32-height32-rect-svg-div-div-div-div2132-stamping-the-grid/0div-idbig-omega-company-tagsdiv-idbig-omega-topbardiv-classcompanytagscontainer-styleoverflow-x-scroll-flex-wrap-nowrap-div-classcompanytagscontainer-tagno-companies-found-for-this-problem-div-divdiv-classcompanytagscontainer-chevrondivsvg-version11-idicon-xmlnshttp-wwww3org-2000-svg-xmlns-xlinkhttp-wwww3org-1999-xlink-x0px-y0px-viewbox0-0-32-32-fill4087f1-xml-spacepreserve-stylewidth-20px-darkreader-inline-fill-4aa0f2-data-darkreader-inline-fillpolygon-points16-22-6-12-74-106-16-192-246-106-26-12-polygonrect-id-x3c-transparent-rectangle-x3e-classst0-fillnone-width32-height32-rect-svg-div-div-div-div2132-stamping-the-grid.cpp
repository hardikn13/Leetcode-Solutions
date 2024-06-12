class Solution {
public:
    void prefixSum(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                grid[i][j] += grid[i][j - 1];
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                grid[j][i] += grid[j - 1][i];
            }
        }
    }
    
    int sum(vector<vector<int>>& mat, int r1, int c1, int r2, int c2)
    {
        int ans = mat[r2][c2];

        if(c1 > 0)
            ans -= mat[r2][c1 - 1];
        if(r1 > 0)
            ans -= mat[r1 - 1][c2];
        if(c1 > 0 && r1 > 0)
            ans += mat[r1 - 1][c1 - 1];
        
        return ans;
    }
    
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> mat = grid;
        prefixSum(mat);
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int bottomRightX = i + stampHeight - 1;
                int bottomRightY = j + stampWidth - 1;
                
                if(bottomRightX >= n || bottomRightY >= m)
                    break;
                
                int val = sum(mat, i, j, bottomRightX, bottomRightY);
                
                if(val == 0)
                    vis[bottomRightX][bottomRightY] = 1;
            }
        }
        
        prefixSum(vis);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int bottomRightX = min(n - 1, i + stampHeight - 1);
                int bottomRightY = min(m - 1, j + stampWidth - 1);
                
                if(grid[i][j] == 0)
                {
                    int val = sum(vis, i, j, bottomRightX, bottomRightY);
                    
                    if(val == 0)
                        return false;
                }
            }
        } 
        
        return true;
    }
};