class Solution {
public:
    int mod = 1e9 + 7;
    long long f(int n, int a, int l, vector<vector<vector<int>>> &dp)
    {
        if(a == 0 || l == 0)
            return 0;
        
        if(n == 0)
            return 1;
        
        if(dp[n][a][l] != -1)
            return dp[n][a][l];
        
        long long ans = f(n - 1, a, 3, dp) % mod;
        ans += f(n - 1, a - 1, 3, dp) % mod;
        ans += f(n - 1, a, l - 1, dp) % mod;
        
        return dp[n][a][l] = ans % mod;
    }
    
    int checkRecord(int n) {
        
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(4, -1)));
        return f(n, 2, 3, dp);

    }
};