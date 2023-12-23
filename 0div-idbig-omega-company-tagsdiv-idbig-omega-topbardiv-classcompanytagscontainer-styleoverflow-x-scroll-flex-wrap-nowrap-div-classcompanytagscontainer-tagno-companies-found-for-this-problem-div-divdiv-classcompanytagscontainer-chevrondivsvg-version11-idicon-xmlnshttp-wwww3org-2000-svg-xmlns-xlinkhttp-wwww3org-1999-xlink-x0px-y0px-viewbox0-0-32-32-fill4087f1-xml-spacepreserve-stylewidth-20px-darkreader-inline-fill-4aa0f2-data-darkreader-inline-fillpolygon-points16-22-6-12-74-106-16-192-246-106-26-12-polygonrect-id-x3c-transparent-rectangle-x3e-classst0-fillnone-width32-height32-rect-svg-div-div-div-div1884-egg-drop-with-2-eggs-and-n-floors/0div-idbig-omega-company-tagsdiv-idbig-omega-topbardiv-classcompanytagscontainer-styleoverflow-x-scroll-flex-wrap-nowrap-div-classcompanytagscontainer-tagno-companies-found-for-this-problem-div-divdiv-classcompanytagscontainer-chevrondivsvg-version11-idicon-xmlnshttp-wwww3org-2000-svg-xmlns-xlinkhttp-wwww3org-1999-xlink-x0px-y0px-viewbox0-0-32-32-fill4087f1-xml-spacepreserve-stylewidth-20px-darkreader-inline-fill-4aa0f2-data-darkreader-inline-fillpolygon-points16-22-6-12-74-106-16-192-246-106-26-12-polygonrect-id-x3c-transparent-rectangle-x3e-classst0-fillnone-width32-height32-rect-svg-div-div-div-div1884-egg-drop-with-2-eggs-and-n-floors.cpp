class Solution {
public:
    int f(int eggs, int n, vector<vector<int>> &dp)
    {
        if(eggs == 1)
            return n;
        
        if(n == 0 || n == 1)
            return n;
        
        if(dp[eggs][n] != -1)
            return dp[eggs][n];

        int mini = INT_MAX;
        for(int i = 1; i < n; i++)
        {
            int breaks = f(eggs - 1, i - 1, dp);
            int notBreak = f(eggs, n - i, dp);
            int ans = 1 + max(breaks, notBreak);
            mini = min(mini, ans);
        }
        
        return dp[eggs][n] = mini;
        
    }
    
    int twoEggDrop(int n) {
        
        int eggs = 2;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return f(eggs, n, dp);
    }
};