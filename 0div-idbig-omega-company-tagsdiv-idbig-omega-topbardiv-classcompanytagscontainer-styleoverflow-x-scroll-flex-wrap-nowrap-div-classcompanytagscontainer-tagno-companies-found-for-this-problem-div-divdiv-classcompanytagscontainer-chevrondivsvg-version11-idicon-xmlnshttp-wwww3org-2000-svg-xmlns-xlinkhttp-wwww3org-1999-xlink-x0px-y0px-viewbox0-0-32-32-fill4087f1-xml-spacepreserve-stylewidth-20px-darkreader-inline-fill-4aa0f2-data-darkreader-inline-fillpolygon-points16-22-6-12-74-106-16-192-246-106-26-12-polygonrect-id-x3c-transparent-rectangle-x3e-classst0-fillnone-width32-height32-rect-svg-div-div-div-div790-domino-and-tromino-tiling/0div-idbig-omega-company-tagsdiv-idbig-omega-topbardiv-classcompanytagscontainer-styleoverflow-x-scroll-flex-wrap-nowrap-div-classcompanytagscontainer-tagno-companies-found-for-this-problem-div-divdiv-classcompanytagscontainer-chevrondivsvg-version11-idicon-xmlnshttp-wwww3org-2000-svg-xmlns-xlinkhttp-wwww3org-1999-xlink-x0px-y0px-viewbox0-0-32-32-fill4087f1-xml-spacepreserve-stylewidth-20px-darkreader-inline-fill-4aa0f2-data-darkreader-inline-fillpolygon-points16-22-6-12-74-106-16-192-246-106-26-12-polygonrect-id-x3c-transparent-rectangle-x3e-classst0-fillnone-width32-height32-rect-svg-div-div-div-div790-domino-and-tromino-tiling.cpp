class Solution {
public:
    
    int mod = 1e9 + 7;
    int numTilings(int n) {
        vector<int> dp(n + 1, 0);
        
        if(n == 1 || n == 2)
            return n;
        else if(n == 3)
            return 5;
        
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        
        for(int i = 4; i <= n; i++)
            dp[i] = ((2 * (dp[i - 1] % mod)) % mod + (dp[i - 3] % mod)) % mod;
        
        return dp[n];
    }
};





// MEMOIZATION
// -----------

// class Solution {
// public:
    
//     int mod = 1e9 + 7;
//     int f(int n, vector<int> &dp)
//     {
//         if(n == 1 || n == 2)
//             return n;
//         else if(n == 3)
//             return 5;
        
//         if(dp[n] != -1)
//             return dp[n];
            
//         return dp[n] = ((2 * (f(n - 1, dp) % mod)) % mod + (f(n - 3, dp) % mod)) % mod;
//     }
    
//     int numTilings(int n) {
//         vector<int> dp(n + 1, -1);
//         return f(n, dp);
//     }
// };