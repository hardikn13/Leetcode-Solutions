class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        vector<int> curr(2, 0), ahead(2, 0);
        
        for(int ind = n - 1; ind >= 0; ind--)
        {
            curr[1] = max(ahead[1], ahead[0] - prices[ind] - fee);
            curr[0] = max(ahead[0], prices[ind] + ahead[1]);
            
            ahead = curr;
        }
        
        return curr[1];
    }
};






// MEMOIZATION
// -----------

// int f(int ind, int buy, vector<int> prices, int fee, vector<vector<int>> &dp)
//     {
//         if(ind >= prices.size())
//             return 0;
        
//         if(dp[ind][buy] != -1)
//             return dp[ind][buy];
        
//         if(buy)
//         {
//             dp[ind][buy] = max(f(ind + 1, 1, prices, fee, dp),
//                 f(ind + 1, 0, prices, fee, dp) - prices[ind] - fee);
//         }
//         else
//         {
//             dp[ind][buy] = max(f(ind + 1, 0, prices, fee, dp),
//                        prices[ind] + f(ind + 1, 1, prices, fee, dp));
//         }
        
//         return dp[ind][buy];
//     }
    
//     int maxProfit(vector<int>& prices, int fee) {
        
//         int n = prices.size();
//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
//         return f(0, 1, prices, fee, dp);
//     }







// TABULATION
// ----------

// int maxProfit(vector<int>& prices, int fee) {
        
//         int n = prices.size();
//         vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        
//         for(int ind = n - 1; ind >= 0; ind--)
//         {
//             for(int buy = 0; buy < 2; buy++)
//             {
//                 if(buy)
//                 {
//                     dp[ind][buy] = max(dp[ind + 1][1],
//                         dp[ind + 1][0] - prices[ind] - fee);
//                 }
//                 else
//                 {
//                     dp[ind][buy] = max(dp[ind + 1][0],
//                                prices[ind] + dp[ind + 1][1]);
//                 }
//             }
//         }
        
//         return dp[0][1];
//     }