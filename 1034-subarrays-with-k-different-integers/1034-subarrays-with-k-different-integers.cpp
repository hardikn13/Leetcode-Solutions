class Solution {
public:
    int f(vector<int>& nums, int k) {
        if(k < 0)
            return 0;

        unordered_map<int, int> mp;
        int n = nums.size();
        int cnt = 0;
        int i = 0, j = 0;

        while(j < n)
        {
            mp[nums[j]]++;
            if(mp.size() <= k)
                cnt += (j - i + 1);
            else
            {
                while(mp.size() > k)
                {
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0)
                        mp.erase(nums[i]);
                    
                    i++;
                }

                cnt += (j - i + 1);
            }

            j++;
        }

        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k - 1);
    }
};