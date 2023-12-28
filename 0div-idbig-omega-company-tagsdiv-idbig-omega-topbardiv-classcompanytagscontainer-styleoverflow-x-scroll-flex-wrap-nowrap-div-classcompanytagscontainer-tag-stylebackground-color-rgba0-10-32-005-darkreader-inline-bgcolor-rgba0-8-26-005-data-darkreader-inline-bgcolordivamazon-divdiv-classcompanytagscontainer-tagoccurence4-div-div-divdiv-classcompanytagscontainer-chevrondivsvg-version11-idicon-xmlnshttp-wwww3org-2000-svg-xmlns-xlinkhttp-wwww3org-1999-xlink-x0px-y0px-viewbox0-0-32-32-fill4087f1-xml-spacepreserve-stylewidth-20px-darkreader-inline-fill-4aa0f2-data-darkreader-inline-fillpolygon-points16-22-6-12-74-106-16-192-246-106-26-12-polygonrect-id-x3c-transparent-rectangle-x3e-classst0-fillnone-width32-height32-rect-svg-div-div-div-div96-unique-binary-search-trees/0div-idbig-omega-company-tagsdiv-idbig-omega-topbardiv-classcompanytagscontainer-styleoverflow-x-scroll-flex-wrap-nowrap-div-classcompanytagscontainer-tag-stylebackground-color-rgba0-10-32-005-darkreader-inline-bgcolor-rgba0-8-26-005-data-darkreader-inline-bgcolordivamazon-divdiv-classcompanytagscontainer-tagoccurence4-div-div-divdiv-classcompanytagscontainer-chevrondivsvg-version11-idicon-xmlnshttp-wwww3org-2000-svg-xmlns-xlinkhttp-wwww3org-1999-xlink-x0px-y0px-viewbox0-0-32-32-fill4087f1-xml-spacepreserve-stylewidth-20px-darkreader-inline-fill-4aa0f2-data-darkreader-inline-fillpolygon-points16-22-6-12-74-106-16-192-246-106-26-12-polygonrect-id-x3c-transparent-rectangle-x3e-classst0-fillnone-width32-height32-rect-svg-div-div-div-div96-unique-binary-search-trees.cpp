class Solution {
public:
    int f(int ind, int ans, vector<int> &dp)
    {
        if(ind <= 1)
            return 1;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        for(int i = 1; i <= ind; i++)
        {
            ans += f(i - 1, ans, dp) * f(ind - i, ans, dp);
        }
        
        return dp[ind] = ans;
    }
    
    int numTrees(int n) {
        
        vector<int> dp(n + 1, -1);
        int ans = 0;
        return f(n, ans, dp);
    }
};