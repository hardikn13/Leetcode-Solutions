class Solution {
public:

    
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for(int j = 0; j <= m; j++)
            prev[j] = j;
        
        for(int i = 1; i <= n; i++)
        {
            curr[0] = i;
            
            for(int j = 1; j <= m; j++)
            {
                if(word1[i - 1] == word2[j - 1])
                    curr[j] = prev[j - 1];
                else
                    curr[j] = 1 + min(prev[j], min(prev[j - 1], curr[j - 1]));
            }
            prev = curr;
        }
        return prev[m];
    }
};







// TABULATION
// ----------

// CHANGING INDEX BY -1

// int minDistance(string word1, string word2) {
        
//         int n = word1.size();
//         int m = word2.size();
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
//         for(int i = 0; i <= n; i++)
//              dp[i][0] = i;
//         for(int j = 0; j <= m; j++)
//              dp[0][j] = j;
        
//         for(int i = 1; i <= n; i++)
//         {
//             for(int j = 1; j <= m; j++)
//             {
//                 if(word1[i - 1] == word2[j - 1])
//                 {
//                     dp[i][j] = dp[i - 1][j - 1];
//                 }
//                 else
//                 {
//                     dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
//                 }
//             }
//         }
        
//         return dp[n][m];
//     }











// MEMOIZATION
// -----------

// int f(int i, int j, string &text1, string &text2, vector<vector<int>> &dp)
//     {
//         if(i < 0)
//             return j + 1;
//         if(j < 0)
//             return i + 1;
        
//         if(dp[i][j] != -1)
//             return dp[i][j];
        
//         if(text1[i] == text2[j])
//             return dp[i][j] = 0 + f(i - 1, j - 1, text1, text2, dp);
//         else
//             return dp[i][j] = 1 + min(f(i - 1, j, text1, text2, dp), "DELETE"
//                                       min(f(i, j - 1, text1, text2, dp), "INSERT"
//                                           f(i - 1, j - 1, text1, text2, dp))); "REPLACE"
//     }
    
    
//     int minDistance(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();
        
//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         return f(n - 1, m - 1, word1, word2, dp);
//     }