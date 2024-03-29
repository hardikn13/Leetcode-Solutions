class Solution {
public:
    
    int f(int ind, int t, vector<int> &coins, vector<vector<int>> &dp)
    {
        if(ind == 0)
        {
            return t % coins[0] == 0;
        }
        
        if(dp[ind][t] != -1)
            return dp[ind][t];
        
        int notTake = f(ind - 1, t, coins, dp);
        int take = 0;
        
        if(coins[ind] <= t)
            take = f(ind, t - coins[ind], coins, dp);
        
        return dp[ind][t] = take + notTake;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
        
        for(int t = 0; t <= amount; t++)
        {
            prev[t] = (t % coins[0] == 0);
        }
        
        for(int ind = 1; ind < n; ind++)
        {
            for(int t = 0; t <= amount; t++)
            {
                int notTake = prev[t];
                int take = 0;

                if(coins[ind] <= t)
                    take = curr[t - coins[ind]];

                curr[t] = take + notTake;
            }
            prev = curr;
        }
        return prev[amount];
    }
};





// TABULATION
// ----------

// int f(int ind, int t, vector<int> &coins, vector<vector<int>> &dp)
//     {
//         if(ind == 0)
//         {
//             return t % coins[0] == 0;
//         }
        
//         if(dp[ind][t] != -1)
//             return dp[ind][t];
        
//         int notTake = f(ind - 1, t, coins, dp);
//         int take = 0;
        
//         if(coins[ind] <= t)
//             take = f(ind, t - coins[ind], coins, dp);
        
//         return dp[ind][t] = take + notTake;
//     }
    
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        
//         for(int t = 0; t <= amount; t++)
//         {
//             dp[0][t] = (t % coins[0] == 0);
//         }
        
//         for(int ind = 1; ind < n; ind++)
//         {
//             for(int t = 0; t <= amount; t++)
//             {
//                 int notTake = dp[ind - 1][t];
//                 int take = 0;

//                 if(coins[ind] <= t)
//                     take = dp[ind][t - coins[ind]];

//                 dp[ind][t] = take + notTake;
//             }
//         }
//         return dp[n - 1][amount];
//     }





// MEMOIZATION
// ----------

//     int f(int ind, int t, vector<int> &coins, vector<vector<int>> &dp)
//     {
//         if(ind == 0)
//         {
//             return t % coins[0] == 0;
//         }
        
//         if(dp[ind][t] != -1)
//             return dp[ind][t];
        
//         int notTake = f(ind - 1, t, coins, dp);
//         int take = 0;
        
//         if(coins[ind] <= t)
//             take = f(ind, t - coins[ind], coins, dp);
        
//         return dp[ind][t] = take + notTake;
//     }
    
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
//         return f(n - 1, amount, coins, dp);
//     }






// RECURSION
// ---------

// int f(int ind, int t, vector<int> &coins)
//     {
//         if(ind == 0)
//         {
//             return t % coins[0] == 0;
//         }
        
//         int notTake = f(ind - 1, t, coins);
//         int take = 0;
        
//         if(coins[ind] <= t)
//             take = f(ind, t - coins[ind], coins);
        
//         return take + notTake;
//     }
    
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         return f(n - 1, amount, coins);
//     }