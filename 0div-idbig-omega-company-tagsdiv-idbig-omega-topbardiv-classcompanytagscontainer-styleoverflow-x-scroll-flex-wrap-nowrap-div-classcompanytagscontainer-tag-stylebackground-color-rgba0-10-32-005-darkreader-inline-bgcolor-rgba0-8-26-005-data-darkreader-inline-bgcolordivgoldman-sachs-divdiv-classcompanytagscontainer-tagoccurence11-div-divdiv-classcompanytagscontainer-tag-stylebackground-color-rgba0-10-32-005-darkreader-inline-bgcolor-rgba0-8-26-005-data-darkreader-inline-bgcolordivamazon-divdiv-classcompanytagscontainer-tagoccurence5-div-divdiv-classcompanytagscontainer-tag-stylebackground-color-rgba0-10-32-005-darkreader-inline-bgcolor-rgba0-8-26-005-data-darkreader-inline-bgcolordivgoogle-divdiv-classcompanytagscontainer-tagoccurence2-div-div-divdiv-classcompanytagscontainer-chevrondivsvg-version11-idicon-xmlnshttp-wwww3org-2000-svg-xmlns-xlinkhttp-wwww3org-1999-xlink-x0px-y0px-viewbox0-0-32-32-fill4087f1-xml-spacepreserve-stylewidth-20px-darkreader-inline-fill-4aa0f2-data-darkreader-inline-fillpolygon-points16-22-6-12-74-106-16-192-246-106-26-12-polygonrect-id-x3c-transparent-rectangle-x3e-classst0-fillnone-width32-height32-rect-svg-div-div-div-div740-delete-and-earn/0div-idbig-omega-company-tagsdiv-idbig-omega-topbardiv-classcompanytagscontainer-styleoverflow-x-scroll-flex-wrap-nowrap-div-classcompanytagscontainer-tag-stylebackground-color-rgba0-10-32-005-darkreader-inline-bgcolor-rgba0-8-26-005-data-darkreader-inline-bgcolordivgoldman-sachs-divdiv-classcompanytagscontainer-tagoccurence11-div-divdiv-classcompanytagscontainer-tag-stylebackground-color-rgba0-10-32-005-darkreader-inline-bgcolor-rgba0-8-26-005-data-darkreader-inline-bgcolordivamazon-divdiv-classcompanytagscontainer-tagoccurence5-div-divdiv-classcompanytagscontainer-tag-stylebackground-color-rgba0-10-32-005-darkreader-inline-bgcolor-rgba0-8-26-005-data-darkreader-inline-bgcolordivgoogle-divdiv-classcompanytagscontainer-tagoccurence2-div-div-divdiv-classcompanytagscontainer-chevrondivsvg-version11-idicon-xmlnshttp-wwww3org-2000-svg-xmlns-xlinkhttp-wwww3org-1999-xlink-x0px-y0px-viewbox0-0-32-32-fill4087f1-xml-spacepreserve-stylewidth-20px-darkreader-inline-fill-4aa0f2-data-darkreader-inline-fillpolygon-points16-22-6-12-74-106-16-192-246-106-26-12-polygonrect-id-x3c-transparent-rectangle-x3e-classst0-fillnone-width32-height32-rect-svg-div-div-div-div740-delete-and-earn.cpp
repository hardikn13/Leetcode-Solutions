class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int n = 10001;
        vector<int> sum(n, 0), dp(n, 0);
        
        for(auto it : nums)
            sum[it] += it;
        
        dp[0] = 0;
        dp[1] = sum[1];
        
        for(int ind = 2; ind < n; ind++)
        {
            int notTake = dp[ind - 1];
            int take = sum[ind] + dp[ind - 2];

            dp[ind] = max(take, notTake);
        }
        
        return dp[n - 1];
    }
};





// RECURSION
// ---------

// int f(int ind, vector<int> sum)
//     {
//         if(ind < 0)
//             return 0;
        
//         int notTake = f(ind - 1, sum);
//         int take = sum[ind] + f(ind - 2, sum);
        
//         return max(take, notTake);
//     }
    
//     int deleteAndEarn(vector<int>& nums) {
        
//         int n = 10001;
//         vector<int> sum(n, 0);
        
//         for(auto it : nums)
//             sum[it] += it;
        
//         return f(n - 1, sum);
//     }





// MEMOIZATION
// -----------

// int f(int ind, vector<int> sum, vector<int> &dp)
//     {
//         if(ind < 0)
//             return 0;
        
//         if(dp[ind] != -1)
//             return dp[ind];
        
//         int notTake = f(ind - 1, sum, dp);
//         int take = sum[ind] + f(ind - 2, sum, dp);
        
//         return dp[ind] = max(take, notTake);
//     }
    
//     int deleteAndEarn(vector<int>& nums) {
        
//         int n = 10001;
//         vector<int> sum(n, 0), dp(n, -1);
        
//         for(auto it : nums)
//             sum[it] += it;
        
//         return f(n - 1, sum, dp);
//     }