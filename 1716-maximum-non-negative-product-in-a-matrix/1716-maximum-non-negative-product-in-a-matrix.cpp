class Solution {
public:
    int mod = 1e9 + 7;
    
    pair<long long, long long> f(int i, int j, vector<vector<int>> &grid, vector<vector<pair<long long, long long>>> &dp) {
        int n = grid.size();
        int m = grid[0].size();

        if(i < 0 || j < 0 || i >= n || j >= m) 
            return {LLONG_MIN, LLONG_MAX};

        if(dp[i][j].first != LLONG_MIN) 
            return dp[i][j];

        if(i == n - 1 && j == m - 1)
        {
            long long prod = grid[i][j];
            return dp[i][j] = {prod, prod};
        }

        auto right = f(i, j + 1, grid, dp);
        auto down = f(i + 1, j, grid, dp);

        long long curMax = LLONG_MIN;
        long long curMin = LLONG_MAX;

        if(right.first != LLONG_MIN)
        {
            curMax = max(curMax, max(right.first * grid[i][j], right.second * grid[i][j]));
            curMin = min(curMin, min(right.first * grid[i][j], right.second * grid[i][j]));
        }
        if(down.first != LLONG_MIN)
        {
            curMax = max(curMax, max(down.first * grid[i][j], down.second * grid[i][j]));
            curMin = min(curMin, min(down.first * grid[i][j], down.second * grid[i][j]));
        }

        return dp[i][j] = {curMax, curMin};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<pair<long long, long long>>> dp(n, vector<pair<long long, long long>>(m, {LLONG_MIN, LLONG_MAX}));

        long long result = f(0, 0, grid, dp).first;
        return result < 0 ? -1 : result % mod;
    }
};
