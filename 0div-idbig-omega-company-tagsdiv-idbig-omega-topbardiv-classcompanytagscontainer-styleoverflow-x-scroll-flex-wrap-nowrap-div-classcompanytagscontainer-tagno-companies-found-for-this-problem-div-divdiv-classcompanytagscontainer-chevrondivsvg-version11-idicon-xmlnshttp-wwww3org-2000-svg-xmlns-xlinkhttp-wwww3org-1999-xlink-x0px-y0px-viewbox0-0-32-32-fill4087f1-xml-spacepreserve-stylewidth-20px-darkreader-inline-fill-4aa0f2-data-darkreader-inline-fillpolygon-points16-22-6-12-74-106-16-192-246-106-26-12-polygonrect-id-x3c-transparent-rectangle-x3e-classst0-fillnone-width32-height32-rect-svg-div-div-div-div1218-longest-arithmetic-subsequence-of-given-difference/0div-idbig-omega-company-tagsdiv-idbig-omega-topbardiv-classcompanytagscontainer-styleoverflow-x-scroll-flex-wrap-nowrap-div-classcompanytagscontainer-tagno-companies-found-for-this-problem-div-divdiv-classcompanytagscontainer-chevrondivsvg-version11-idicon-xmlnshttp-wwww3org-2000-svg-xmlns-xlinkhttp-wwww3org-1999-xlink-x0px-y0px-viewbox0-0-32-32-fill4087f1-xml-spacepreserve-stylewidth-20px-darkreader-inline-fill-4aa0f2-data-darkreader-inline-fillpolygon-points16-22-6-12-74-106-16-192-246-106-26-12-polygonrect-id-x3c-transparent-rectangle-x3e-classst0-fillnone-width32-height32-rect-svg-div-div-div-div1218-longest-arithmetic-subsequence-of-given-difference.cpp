class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        unordered_map<int,int> mp;
        int n = arr.size(), ans = 1;
        
        for(int i = n - 1; i >= 0; i--)
        {
            mp[arr[i]] = mp[arr[i] + difference] + 1;
            ans = max(ans, mp[arr[i]]);
        }
        
        return ans; 
    }
};






// RECURSION
// ---------

// int f(int ind, vector<int> arr, int difference, int &prev)
//     {
//         if(ind >= arr.size())
//             return 0;
        
//         int notTake = 0;
//         int take = 0;
        
//         if(prev == -100000)
//         {
//             take = 1 + f(ind + 1, arr, difference, arr[ind]);
//             notTake = f(ind + 1, arr, difference, prev);
//         }
//         else
//         {
//             notTake = f(ind + 1, arr, difference, prev);
//             if(prev == arr[ind] - difference)
//                 take = 1 + f(ind + 1, arr, difference, arr[ind]);
//         }
        
//         return max(take, notTake);
//     }
    
//     int longestSubsequence(vector<int>& arr, int difference) {
        
//         int n = arr.size(), prev = -100000;
//         return f(0, arr, difference, prev);
//     }







// MEMOIZATION
// -----------

// int f(int ind, vector<int> arr, int difference, int &prev, vector<vector<int>> &dp)
//     {
//         if(ind >= arr.size())
//             return 0;
        
//         if(dp[ind][prev + 10000] != -1)
//             return dp[ind][prev + 10000];
        
//         int notTake = f(ind + 1, arr, difference, prev, dp);
        
//         int take = 0;
//         if(prev == -10000 || prev == arr[ind] - difference)
//         {
//             take = 1 + f(ind + 1, arr, difference, arr[ind], dp);
//         }
        
//         return dp[ind][prev + 10000] = max(take, notTake);
//     }
    
//     int longestSubsequence(vector<int>& arr, int difference) {
        
//         int n = arr.size(), prev = -10000;
//         vector<vector<int>> dp(n + 1, vector<int> (20001, -1));
//         return f(0, arr, difference, prev, dp);
//     }