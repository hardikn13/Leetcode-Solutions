class Solution {
public:
    int f(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        int n = grid.size();
        int m = grid[0].size(); 
        
        if(row == n)
            return 0;
        
        if(dp[row][col] != -1)
            return dp[row][col];
        
        int res = INT_MAX;
        for(int j = 0; j < m; j++)
        {
            if(j == col)
                continue;
            
            res = min(res, grid[row][j] + f(row + 1, j, grid, dp));
        }
        
        return dp[row][col] = res;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        int ans = INT_MAX;
        for(int j = 0; j < m; j++)
            ans = min(ans, grid[0][j] + f(1, j, grid, dp));
        
        return ans;
    }
};