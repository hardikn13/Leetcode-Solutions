class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> dp(26, 0);
        int ans = 0;
        
        for(int ind = 0; ind < n; ind++)
        {
            int maxi = 0;
            for(char last = 'a'; last <= 'z'; last++)
            {
                if(abs(last - s[ind]) <= k)
                    maxi = max(maxi, 1 + dp[last - 'a']);
            }
            
            dp[s[ind] - 'a'] = maxi;
            ans = max(ans, maxi);
        }
        
        return ans;
    }
};





// MEMOIZATION
// -----------

// class Solution {
// public:
//     int f(int ind, char last, string s, int k, vector<vector<int>> &dp)
//     {
//         if(ind == s.size())
//             return 0;
        
//         if(dp[ind][last - 'a'] != -1)
//             return dp[ind][last - 'a'];
        
//         int notTake = f(ind + 1, last, s, k, dp);
        
//         int take = 0;
//         if(last == '{' || abs(last - s[ind]) <= k)
//             take = 1 + f(ind + 1, s[ind], s, k, dp);
        
//         return dp[ind][last - 'a'] = max(take, notTake);
//     }
    
//     int longestIdealString(string s, int k) {
//         int n = s.size();
//         vector<vector<int>> dp(n, vector<int>(27, -1));
//         return f(0, '{', s, k, dp);
//     }
// };