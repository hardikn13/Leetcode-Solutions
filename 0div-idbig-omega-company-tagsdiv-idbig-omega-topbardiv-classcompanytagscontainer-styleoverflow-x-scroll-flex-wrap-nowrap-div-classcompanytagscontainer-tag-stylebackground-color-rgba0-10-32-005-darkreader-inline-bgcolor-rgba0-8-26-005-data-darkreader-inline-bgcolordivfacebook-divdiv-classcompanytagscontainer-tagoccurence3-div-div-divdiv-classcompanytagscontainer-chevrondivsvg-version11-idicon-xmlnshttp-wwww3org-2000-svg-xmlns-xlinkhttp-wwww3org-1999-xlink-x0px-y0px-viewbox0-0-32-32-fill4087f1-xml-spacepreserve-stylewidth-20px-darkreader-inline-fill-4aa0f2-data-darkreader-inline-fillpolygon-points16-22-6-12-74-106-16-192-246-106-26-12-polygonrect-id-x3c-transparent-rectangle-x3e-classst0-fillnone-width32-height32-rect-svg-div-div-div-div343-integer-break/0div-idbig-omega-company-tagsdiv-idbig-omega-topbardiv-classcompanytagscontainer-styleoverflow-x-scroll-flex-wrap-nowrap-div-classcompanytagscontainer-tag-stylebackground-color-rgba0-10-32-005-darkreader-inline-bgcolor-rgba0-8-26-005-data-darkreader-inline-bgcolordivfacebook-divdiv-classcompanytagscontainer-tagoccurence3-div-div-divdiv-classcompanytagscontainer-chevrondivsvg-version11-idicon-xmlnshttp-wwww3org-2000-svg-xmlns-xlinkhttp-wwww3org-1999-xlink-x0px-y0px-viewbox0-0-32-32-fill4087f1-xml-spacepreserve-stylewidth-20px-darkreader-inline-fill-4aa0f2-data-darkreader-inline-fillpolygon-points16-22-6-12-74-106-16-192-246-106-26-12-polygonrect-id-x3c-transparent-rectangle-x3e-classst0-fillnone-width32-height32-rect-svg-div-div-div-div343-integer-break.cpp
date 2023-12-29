class Solution {
public:
    int f(int n, int target, vector<vector<int>> &dp)
    {
        if(n == 1)
            return 1;
        
        if(dp[n][target] != -1)
            return dp[n][target];
        
        int notTake = f(n - 1, target, dp);
        int take = 0;
        if(target >= n)
        {
            take = n * f(n, target - n, dp);
        }
        
        return dp[n][target] = max(take, notTake);
    }
    
    int integerBreak(int n) {
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return f(n - 1, n, dp);
    }
};