class Solution {
public:
    int twoEggDrop(int n) {
        int eggs = 2;
        vector<vector<int>> dp(eggs + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= eggs; i++) {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }

        for (int i = 1; i <= n; i++)
            dp[1][i] = i;

            for (int j = 2; j <= n; j++)
            {
                dp[eggs][j] = INT_MAX;
                for (int k = 1; k <= j; k++)
                {
                    if(eggs == 1)
                        dp[eggs][j] = n;
                    
                    int breaks = dp[eggs - 1][k - 1];
                    int notBreak = dp[eggs][j - k];
                    int maxDrops = 1 + max(breaks, notBreak);
                    dp[eggs][j] = min(dp[eggs][j], maxDrops);
                }
            }

        return dp[eggs][n];
    }
};



// FORMULA
// -------

// int twoEggDrop(int n) {
//     int m = 1;
//     while (m * (m + 1) / 2 < n)
//         ++m;
//     return m;    
// }






// class Solution {
// public:
//     int f(int eggs, int n, vector<vector<int>> &dp)
//     {
//         if(eggs == 1)
//             return n;
        
//         if(n == 0 || n == 1)
//             return n;
        
//         if(dp[eggs][n] != -1)
//             return dp[eggs][n];

//         int mini = INT_MAX;
//         for(int i = 1; i < n; i++)
//         {
//             int breaks = f(eggs - 1, i - 1, dp);
//             int notBreak = f(eggs, n - i, dp);
//             int ans = 1 + max(breaks, notBreak);
//             mini = min(mini, ans);
//         }
        
//         return dp[eggs][n] = mini;
        
//     }
    
//     int twoEggDrop(int n) {
        
//         int eggs = 2;
//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        
//         return f(eggs, n, dp);
//     }
// };