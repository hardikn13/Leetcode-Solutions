class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        
        int mini = INT_MAX;
        for(int j = 0; j < m; j++)
        {
            prev[j] = matrix[n - 1][j];
            mini = min(mini, prev[j]);
        }
        
        prev[m] = mini;
        
        for(int row = n - 2; row >= 0; row--)
        {
            mini = INT_MAX;
            for(int col = 0; col <= m; col++)
            {
                if(col == m)
                {
                    curr[col] = mini;
                    continue;
                }
                
                int t1 = INT_MAX, t2 = INT_MAX, t3 = INT_MAX;
        
                t2 = matrix[row][col] + prev[col];
                if(col > 0)
                    t1 = matrix[row][col] + prev[col - 1];

                if(col < m - 1)
                    t3 = matrix[row][col] + prev[col + 1];

                curr[col] = min(t1, min(t2, t3));
                mini = min(mini, curr[col]);
            }
            prev = curr;
        }
        
        return prev[m];
    }
};









// MEMOIZATION
// -----------

// int f(int row, int col, vector<vector<int>>& matrix, vector<vector<int>> &dp)
//     {
//         int n = matrix.size();
//         int m = matrix[0].size();
        
//         if(row == n)
//             return 0;
        
//         if(col < 0 || col > m - 1)
//             return INT_MAX;
        
//         if(dp[row][col] != -1)
//             return dp[row][col];
        
//         int t1 = INT_MAX, t2 = INT_MAX, t3 = INT_MAX;
        
//         t2 = matrix[row][col] + f(row + 1, col, matrix, dp);
//         if(col > 0)
//             t1 = matrix[row][col] + f(row + 1, col - 1, matrix, dp);
            
//         if(col < m - 1)
//             t3 = matrix[row][col] + f(row + 1, col + 1, matrix, dp);
        
//         return dp[row][col] = min(t1, min(t2, t3));
//     }
    
//     int minFallingPathSum(vector<vector<int>>& matrix) {
        
//         int n = matrix.size();
//         int m = matrix[0].size();
//         vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        
//         int ans = INT_MAX;
//         for(int j = 0; j < m; j++)
//         {
//             ans = min(ans, f(0, j, matrix, dp));
//         }
        
//         return ans;
//     }









// TABULATION
// ----------

// int minFallingPathSum(vector<vector<int>>& matrix) {
        
//         int n = matrix.size();
//         int m = matrix[0].size();
//         vector<vector<int>> dp(n, vector<int> (m + 1, 0));
        
//         int mini = INT_MAX;
//         for(int j = 0; j < m; j++)
//         {
//             dp[n - 1][j] = matrix[n - 1][j];
//             mini = min(mini, dp[n - 1][j]);
//         }
        
//         dp[n - 1][m] = mini;
        
//         for(int row = n - 2; row >= 0; row--)
//         {
//             mini = INT_MAX;
//             for(int col = 0; col <= m; col++)
//             {
//                 if(col == m)
//                 {
//                     dp[row][col] = mini;
//                     continue;
//                 }
                
//                 int t1 = INT_MAX, t2 = INT_MAX, t3 = INT_MAX;
        
//                 t2 = matrix[row][col] + dp[row + 1][col];
//                 if(col > 0)
//                     t1 = matrix[row][col] + dp[row + 1][col - 1];

//                 if(col < m - 1)
//                     t3 = matrix[row][col] + dp[row + 1][col + 1];

//                 dp[row][col] = min(t1, min(t2, t3));
//                 mini = min(mini, dp[row][col]);
//             }
//         }
        
//         return dp[0][m];
//     }