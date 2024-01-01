class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        
        int n = nums.size(), remainder = 0;
        vector<int> prev(3, 0), curr(3, 0);
        
        prev[0] = 0;
        prev[1] = INT_MIN;
        prev[2] = INT_MIN;

        for(int ind = 1; ind <= n; ind++)
        {
            for(int remainder = 0; remainder < 3; remainder++)
            {
                int notTake = prev[remainder];
                int take = nums[ind - 1] + prev[(remainder + nums[ind - 1]) % 3];

                curr[remainder] = max(take, notTake);
            }
            
            prev = curr;
        }
        
        return prev[0];
    }
};






// RECURSION
// ---------

// int f(int ind, vector<int> nums, int sum)
//     {
//         if(ind < 0)
//         {
//             if(sum % 3 == 0)
//                 return sum;
//             else
//                 return INT_MIN;
//         }
        
//         int notTake = f(ind - 1, nums, sum);
//         int take = f(ind - 1, nums, sum + nums[ind]);
        
//         return max(take, notTake);
//     }
    
//     int maxSumDivThree(vector<int>& nums) {
        
//         int n = nums.size(), sum = 0;
//         return f(n - 1, nums, sum);
//     }







// MEMOIZATION
// -----------

// int f(int ind, vector<int> nums, int remainder, vector<vector<int>> &dp)
//     {
//         if(ind < 0)
//         {
//             if(remainder == 0)
//                 return 0;
//             else
//                 return INT_MIN;
//         }
        
//         if(dp[ind][remainder] != -1)
//             return dp[ind][remainder];
        
//         int notTake = f(ind - 1, nums, remainder, dp);
//         int take = nums[ind] + f(ind - 1, nums, (remainder + nums[ind]) % 3, dp);
        
//         return dp[ind][remainder] = max(take, notTake);
//     }
    
//     int maxSumDivThree(vector<int>& nums) {
        
//         int n = nums.size(), remainder = 0;
//         vector<vector<int>> dp(n + 1, vector<int> (4, -1));
//         return f(n - 1, nums, remainder, dp);
//     }







// TABULATION
// ----------

// int maxSumDivThree(vector<int>& nums) {
        
//         int n = nums.size(), remainder = 0;
//         vector<vector<int>> dp(n + 1, vector<int> (4, 0));
        
//         dp[0][0] = 0;
//         dp[0][1] = INT_MIN;
//         dp[0][2] = INT_MIN;

//         for(int ind = 1; ind <= n; ind++)
//         {
//             for(int remainder = 0; remainder < 3; remainder++)
//             {
//                 int notTake = dp[ind - 1][remainder];
//                 int take = nums[ind - 1] + dp[ind - 1][(remainder + nums[ind - 1]) % 3];

//                 dp[ind][remainder] = max(take, notTake);
//             }
//         }
        
//         return dp[n][0];
//     }