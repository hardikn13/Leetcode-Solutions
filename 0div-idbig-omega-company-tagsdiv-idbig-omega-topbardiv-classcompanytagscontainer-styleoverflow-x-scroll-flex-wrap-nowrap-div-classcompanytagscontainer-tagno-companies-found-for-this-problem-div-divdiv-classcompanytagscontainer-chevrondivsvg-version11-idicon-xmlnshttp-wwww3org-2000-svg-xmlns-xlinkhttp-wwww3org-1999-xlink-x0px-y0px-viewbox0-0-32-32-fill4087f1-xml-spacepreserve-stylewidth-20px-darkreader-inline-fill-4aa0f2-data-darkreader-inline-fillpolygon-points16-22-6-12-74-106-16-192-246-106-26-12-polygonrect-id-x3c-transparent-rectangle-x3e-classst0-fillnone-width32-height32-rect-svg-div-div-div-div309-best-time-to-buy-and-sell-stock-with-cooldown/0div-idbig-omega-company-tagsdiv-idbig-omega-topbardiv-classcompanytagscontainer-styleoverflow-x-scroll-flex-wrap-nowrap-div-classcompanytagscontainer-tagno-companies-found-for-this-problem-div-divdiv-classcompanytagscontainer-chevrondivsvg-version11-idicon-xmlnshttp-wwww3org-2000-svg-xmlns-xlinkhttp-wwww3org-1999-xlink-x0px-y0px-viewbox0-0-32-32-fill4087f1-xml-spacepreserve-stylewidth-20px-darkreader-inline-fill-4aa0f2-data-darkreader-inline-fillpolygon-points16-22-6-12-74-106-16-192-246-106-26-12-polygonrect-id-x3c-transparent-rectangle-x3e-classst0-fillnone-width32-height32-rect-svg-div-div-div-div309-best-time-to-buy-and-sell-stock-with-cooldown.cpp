class Solution {
public:
    int f(int ind, int buy, vector<int> prices, vector<vector<int>> &dp)
    {
        if(ind >= prices.size())
            return 0;
        
        if(dp[ind][buy] != -1)
            return dp[ind][buy];
        
        if(buy)
        {
            dp[ind][buy] = max(f(ind + 1, 0, prices, dp) - prices[ind],
                               f(ind + 1, 1, prices, dp));
        }
        else
        {
            dp[ind][buy] = max(prices[ind] + f(ind + 2, 1, prices, dp),
                               f(ind + 1, 0, prices, dp));
        }
        
        return dp[ind][buy];
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size(), buy = 1;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        
        return f(0, buy, prices, dp);
    }
};