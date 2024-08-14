class Solution {
public:
    int mod = 1e9 + 7;
    int dfs(int row, int col, vector<vector<int>>& dp, vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        if(dp[row][col] != -1)
            return dp[row][col];

        int cnt = 1;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
            grid[nRow][nCol] > grid[row][col])
            {
                cnt = (cnt + dfs(nRow, nCol, dp, grid)) % mod;
            }
        }

        return dp[row][col] = cnt;
    }

    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                ans = (ans + dfs(i, j, dp, grid)) % mod;
            }
        }

        return ans;
    }
};