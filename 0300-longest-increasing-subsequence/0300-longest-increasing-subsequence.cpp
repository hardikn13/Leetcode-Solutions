class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n, 1), hash(n);
        int maxi = 1, lastIndex = 0;
        
        for(int ind = 0; ind < n; ind++)
        {
            hash[ind] = ind;
            for(int prev = 0; prev < ind; prev++)
            {
                if(nums[prev] < nums[ind] && 1 + dp[prev] > dp[ind])
                {
                    dp[ind] = 1 + dp[prev];
                    hash[ind] = prev;
                }
            }
            if(dp[ind] > maxi)
            {
                maxi = dp[ind];
                lastIndex = ind;
            }
        }
        
        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        
        while(hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        
        reverse(temp.begin(), temp.end());
        return maxi;
    }
};




// TABULATION
// ----------

// int lengthOfLIS(vector<int>& nums) {
        
//         int n = nums.size();
//         vector<int> dp(n, 1);
//         int maxi = 1;
        
//         for(int ind = 0; ind < n; ind++)
//         {
//             for(int prev = 0; prev < ind; prev++)
//             {
//                 if(nums[prev] < nums[ind])
//                     dp[ind] = max(dp[ind], 1 + dp[prev]);
//             }
//             maxi = max(maxi, dp[ind]);
//         }
//         return maxi;
//     }





// =========================





// SPACE OPTIMIZED
// ---------------

// int lengthOfLIS(vector<int>& nums) {
        
//         int n = nums.size();
//         vector<int> ahead(n + 1, 0), curr(n + 1, 0);
        
//         for(int ind = n - 1; ind >= 0; ind--)
//         {
//             for(int prev = ind - 1; prev >= -1; prev--)
//             {
//                 int len = ahead[prev + 1]; //NOT TAKE
        
//                 if(prev == -1 || nums[ind] > nums[prev])
//                     len = max(1 + ahead[ind + 1], len); //MAX(TAKE, NOT TAKE)

//                 curr[prev + 1] = len;
//             }
//             ahead = curr;
//         }
//         return ahead[-1 + 1];
//     }













// TABULATION
// ----------

// int lengthOfLIS(vector<int>& nums) {
        
//         int n = nums.size();
//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
//         for(int ind = n - 1; ind >= 0; ind--)
//         {
//             for(int prev = ind - 1; prev >= -1; prev--)
//             {
//                 int len = dp[ind + 1][prev + 1]; //NOT TAKE
        
//                 if(prev == -1 || nums[ind] > nums[prev])
//                     len = max(1 + dp[ind + 1][ind + 1], len); //MAX(TAKE, NOT TAKE)

//                 dp[ind][prev + 1] = len;
//             }
//         }
//         return dp[0][-1 + 1];
//     }












// MEMOIZATION
// -----------

// int f(int ind, int prev, int n, vector<int> &nums, vector<vector<int>> &dp)
//     {
//         if(ind == n)
//             return 0;
        
//         if(dp[ind][prev + 1] != -1)
//             return dp[ind][prev + 1];
        
//         int len = f(ind + 1, prev, n, nums, dp); //NOT TAKE
        
//         if(prev == -1 || nums[ind] > nums[prev])
//             len = max(1 + f(ind + 1, ind, n, nums, dp), len); //MAX(TAKE, NOT TAKE)
            
//         return dp[ind][prev + 1] = len;
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
        
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int>(n + 1, -1));
//         return f(0, -1, n, nums, dp);
//     }










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