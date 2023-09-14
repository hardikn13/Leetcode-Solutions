class Solution {
public:
    
    // NEW METHOD
    // ==========
    
    int f(int ind, int transNo, int k, int n, vector<int>& prices, vector<vector<int>> &dp)
    {
        if(ind == n || transNo == 2 * k)
            return 0;
        
        if(dp[ind][transNo] != -1)
             return dp[ind][transNo];
        
        if(transNo % 2 == 0)
            dp[ind][transNo] = max(-prices[ind] + f(ind + 1, transNo + 1, k, n, prices, dp), 0 + f(ind + 1, transNo, k, n, prices, dp));
        else
            dp[ind][transNo] = max(prices[ind] + f(ind + 1, transNo + 1, k, n, prices, dp), f(ind + 1, transNo, k, n, prices, dp));
        
        return dp[ind][transNo];
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k, -1));
        return f(0, 0, k, n, prices, dp);
    }
};




// STRIVER'S METHOD
// ================


// SPACE OPTIMIZED
// ---------------

// int maxProfit(int k, vector<int>& prices) {
        
//         int n = prices.size();
//         vector<vector<int>> after(2, vector<int>(k + 1, 0));
//         vector<vector<int>> curr(2, vector<int>(k + 1, 0));

//         for(int ind = n - 1; ind >= 0; ind--)
//         {
//             for(int buy = 0; buy < 2; buy++)
//             {
//                 for(int cap = 1; cap < k + 1; cap++)
//                 {
                    
//                     if(buy)
//                         curr[buy][cap] = max(-prices[ind] + after[0][cap], 0 + after[1][cap]);
//                     else
//                         curr[buy][cap] = max(prices[ind] + after[1][cap - 1],after[0][cap]);
//                 }
//             }
//             after = curr;
//         }
//         return after[1][k];
//     }









// TABULATION
// ----------

// int maxProfit(int k, vector<int>& prices) {
        
//                 int n = prices.size();
//                 vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

//                 for(int ind = n - 1; ind >= 0; ind--)
//                 {
//                     for(int buy = 0; buy < 2; buy++)
//                     {
//                         for(int cap = 1; cap <= k; cap++)
//                         {

//                             if(buy)
//                                 dp[ind][buy][cap] = max(-prices[ind] + dp[ind + 1][0][cap], 0 + dp[ind + 1][1][cap]);
//                             else
//                                 dp[ind][buy][cap] = max(prices[ind] + dp[ind + 1][1][cap - 1], dp[ind + 1][0][cap]);
//                         }
//                     }
//                 }
//                 return dp[0][1][k];
//     }