class Solution {
public:
    int integerBreak(int n) {
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        for(int i = 0; i <= n; i++)
        {
            dp[1][i] = 1;
        }
        
        for(int ind = 2; ind < n; ind++)
        {
            for(int target = 0; target <= n; target++)
            {
                int notTake = dp[ind - 1][target];
                int take = 0;
                if(target >= ind)
                {
                    take = ind * dp[ind][target - ind];
                }

                dp[ind][target] = max(take, notTake);
            }
        }
        
        return dp[n - 1][n];
    }
};