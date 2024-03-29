class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        
        for(int j = 0; j <= m; j++)
            prev[j] = 0;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(text1[i - 1] == text2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = 0 + max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return curr[m];
    }
};



// TABULATION
// ----------    
    
// (SHIFTING INDEXES BY 1 INORDER TO WRITE THE BASE CASE)    

//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.size();
//         int m = text2.size();
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
//         for(int i = 0; i <= n; i++)
//             dp[i][0] = 0;
        
//         for(int j = 0; j <= m; j++)
//             dp[0][j] = 0;
        
//         for(int i = 1; i <= n; i++)
//         {
//             for(int j = 1; j <= m; j++)
//             {
//                 if(text1[i - 1] == text2[j - 1])
//                     dp[i][j] = 1 + dp[i - 1][j - 1];
//                 else
//                     dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }
//         return dp[n][m];
//     }






// MEMOIZATION
// -----------

// int f(int i, int j, string &text1, string &text2, vector<vector<int>> &dp)
//     {
//         if(i < 0 || j < 0)
//             return 0;
        
//         if(dp[i][j] != -1)
//             return dp[i][j];
        
//         if(text1[i] == text2[j])
//             return dp[i][j] = 1 + f(i - 1, j - 1, text1, text2, dp);
//         else
//             return dp[i][j]=0+max(f(i-1, j, text1, text2, dp), f(i, j-1, text1, text2, dp));
//     }
    
//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.size();
//         int m = text2.size();
//         vector<vector<int>> dp(m, vector<int>(n, -1));
        
//         return f(n - 1, m - 1, text1, text2, dp);
//     }






// RECURSION
// ---------

// int solve(string &s, string &t, int i, int j){
//         if(i < 0 || j < 0) return 0;

//         if(s[i] == t[j]) return solve(s,t, i-1, j-1) + 1 ;

//         return max(solve(s,t,i-1,j) , solve(s,t,i,j-1));
//     }

// int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.size();
//         int m = text2.size();

//         return solve(text1, text2, n-1, m-1);
//     }