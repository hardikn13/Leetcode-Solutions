class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<long long> pref(n);
        
        long long sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            pref[i] = sum;
        }
        
        long long ans = LONG_MIN;
        for(int i = 0; i < n; i++)
        {
            if(mp.find(nums[i] - k) != mp.end())
            {
                ans = max(ans, pref[i] - pref[mp[nums[i] - k]] + nums[mp[nums[i] - k]]);
            }
            
            
            if(mp.find(nums[i] + k) != mp.end())
            {
                ans = max(ans, pref[i] - pref[mp[nums[i] + k]] + nums[mp[nums[i] + k]]);
            }
            
            if(mp.find(nums[i]) != mp.end())
            {
                mp[nums[i]] = pref[i] < pref[mp[nums[i]]] ? i : mp[nums[i]];
            }
            else
                mp[nums[i]] = i;
        }
        
        return ans == LONG_MIN ? 0 : ans;
    }
};