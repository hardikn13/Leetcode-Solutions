class Solution {
public:
    int f(int ind, vector<pair<int, int>> &v, int k, vector<int> &dp)
    {
        if(ind == v.size())
            return 1;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int notTake = f(ind + 1, v, k, dp);
        int take = (1 << v[ind].second) - 1;
        
        if(ind + 1 < v.size() && v[ind + 1].first - v[ind].first == k)
            take *= f(ind + 2, v, k, dp);
        else
            take *= f(ind + 1, v, k, dp);
        
        return dp[ind] = take + notTake;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1;
        
        map<int, map<int, int>> freq;
        for(int &it : nums)
        {
            freq[it % k][it]++;
        }
        
        for(auto &it : freq)
        {
            vector<pair<int, int>> v(it.second.begin(), it.second.end());
            vector<int> dp(v.size(), -1);
            ans *= f(0, v, k, dp);
        }
        
        return ans - 1;
    }
};







// ANOTHER APPROACH
// ----------------

// void f(int ind, int &ans, vector<int> &nums, int k, unordered_map<int, int> &mp)
//     {
//         if(ind == nums.size())
//             ans++;
//         else
//         {
//             if(!mp[nums[ind] - k] && !mp[nums[ind] + k])
//             {
//                 mp[nums[ind]]++;
//                 f(ind + 1, ans, nums, k, mp);
//                 mp[nums[ind]]--;
//             }
            
//             f(ind + 1, ans, nums, k, mp);
//         }
//     }
    
//     int beautifulSubsets(vector<int>& nums, int k) {
//         int n = nums.size();
//         int ans = 0;
//         unordered_map<int, int> mp;
//         f(0, ans, nums, k, mp);
        
//         return ans - 1;
//     }