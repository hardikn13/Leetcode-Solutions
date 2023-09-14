class Solution {
public:
    
    int f(int ind, int buy, int cap, int n, vector<int> &prices, vector<vector<vector<int>>>&dp)
    {
        if(cap == 0)
            return 0;
        if(ind == n)
            return 0;
        
        if(dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];
        
        int profit = 0;
        
        if(buy)
            dp[ind][buy][cap] = max(-prices[ind] + f(ind + 1, 0, cap, n, prices, dp), 0 + f(ind + 1, 1, cap, n, prices, dp));
        else
            dp[ind][buy][cap] = max(prices[ind] + f(ind + 1, 1, cap - 1, n, prices, dp), f(ind + 1, 0, cap, n, prices, dp));
        
        return dp[ind][buy][cap];
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size(), cap = 2;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, cap, n, prices, dp);
    }
};