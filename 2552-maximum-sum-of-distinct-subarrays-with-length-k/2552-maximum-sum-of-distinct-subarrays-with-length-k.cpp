class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        long long i = 0, j = 0, sum = 0, maxi = 0, count = 0;
        while(j < n)
        {
            mp[nums[j]]++;
            sum += nums[j];
            if(mp[nums[j]] == 1)
            {
                count++;
            }
            if(j - i + 1 < k)
            {
                j++;
            }
            else
            {
                if(count == k)
                {
                    maxi = max(maxi, sum);
                }
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                {
                    count--;
                }
                sum -= nums[i];
                j++;
                i++;
            }
        }
        return maxi;
    }
};