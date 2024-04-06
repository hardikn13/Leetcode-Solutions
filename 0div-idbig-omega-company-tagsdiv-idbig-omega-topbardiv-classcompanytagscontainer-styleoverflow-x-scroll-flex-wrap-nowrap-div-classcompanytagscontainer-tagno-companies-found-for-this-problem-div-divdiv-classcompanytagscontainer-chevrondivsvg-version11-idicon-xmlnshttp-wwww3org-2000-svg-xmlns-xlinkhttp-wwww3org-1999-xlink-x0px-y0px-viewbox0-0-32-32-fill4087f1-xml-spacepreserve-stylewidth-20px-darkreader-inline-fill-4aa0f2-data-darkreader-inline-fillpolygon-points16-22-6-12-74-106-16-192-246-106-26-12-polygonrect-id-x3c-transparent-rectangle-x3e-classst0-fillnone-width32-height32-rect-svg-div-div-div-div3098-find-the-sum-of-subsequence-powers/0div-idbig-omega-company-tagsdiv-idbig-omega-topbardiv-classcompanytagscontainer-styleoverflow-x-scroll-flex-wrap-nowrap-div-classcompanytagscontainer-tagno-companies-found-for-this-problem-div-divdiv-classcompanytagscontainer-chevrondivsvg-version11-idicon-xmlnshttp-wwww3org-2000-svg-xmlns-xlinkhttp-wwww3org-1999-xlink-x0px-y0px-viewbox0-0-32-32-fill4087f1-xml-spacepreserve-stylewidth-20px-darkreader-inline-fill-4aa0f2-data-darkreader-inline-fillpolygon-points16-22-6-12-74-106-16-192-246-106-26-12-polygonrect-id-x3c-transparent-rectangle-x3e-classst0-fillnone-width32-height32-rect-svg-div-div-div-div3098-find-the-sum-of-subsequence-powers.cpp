class Solution {
public:
    
    unordered_map<long long, unordered_map<long long, unordered_map<long long, unordered_map<long long, long long>>>> dp;
    int mod = 1e9 + 7;
    
    int f(int ind, int remK, int lastIndex, long long minDiff, vector<int>& nums)
    {
        if(remK == 0)
            return minDiff % mod;
        
        if(ind == nums.size())
            return 0;
        
        if(dp.count(ind) && dp[ind].count(remK) && dp[ind][remK].count(lastIndex) &&
           dp[ind][remK][lastIndex].count(minDiff))
            return dp[ind][remK][lastIndex][minDiff];
        
        long long newDiff = (lastIndex == -1) ? LONG_MAX : min(minDiff,
                            (long long)abs(nums[lastIndex] - nums[ind]));
        
        int take = f(ind + 1, remK - 1, ind, newDiff, nums);
        int notTake = f(ind + 1, remK, lastIndex, minDiff, nums);
                     
        return dp[ind][remK][lastIndex][minDiff] = (take + notTake) % mod;
    }
    
    int sumOfPowers(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return f(0, k, -1, LONG_MAX, nums);
    }
};