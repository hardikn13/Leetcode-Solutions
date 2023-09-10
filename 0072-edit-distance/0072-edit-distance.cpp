class Solution {
public:

    
    int f(int i, int j, string &text1, string &text2, vector<vector<int>> &dp)
    {
        if(i < 0)
            return j + 1;
        if(j < 0)
            return i + 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(text1[i] == text2[j])
            return dp[i][j] = 0 + f(i - 1, j - 1, text1, text2, dp);
        else
            return dp[i][j] = 1 + min(f(i - 1, j, text1, text2, dp),
                                      min(f(i, j - 1, text1, text2, dp),
                                          f(i - 1, j - 1, text1, text2, dp)));
    }
    
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, word1, word2, dp);
    }
};