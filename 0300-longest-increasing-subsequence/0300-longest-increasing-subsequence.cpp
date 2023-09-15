class Solution {
public:
    
    int f(int ind, int prev, int n, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(ind == n)
            return 0;
        
        if(dp[ind][prev + 1] != -1)
            return dp[ind][prev + 1];
        
        int len = f(ind + 1, prev, n, nums, dp); //NOT TAKE
        
        if(prev == -1 || nums[ind] > nums[prev])
            len = max(1 + f(ind + 1, ind, n, nums, dp), len); //MAX(TAKE, NOT TAKE)
            
        return dp[ind][prev + 1] = len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, n, nums, dp);
    }
};







// RECURSION
// ---------

// int f(int ind, int prev, int n, vector<int> &nums)
//     {
//         if(ind == n)
//             return 0;
        
//         int take;
//         int notTake = f(ind + 1, prev, n, nums);
        
//         if(prev == -1 || nums[ind] > nums[prev])
//             take = max(1 + f(ind + 1, ind, n, nums), notTake);
            
//         return take;
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
        
//         int n = nums.size();
//         return f(0, -1, n, nums);
//     }