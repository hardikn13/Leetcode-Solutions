class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;
        int maxi = *max_element(nums.begin(), nums.end());
        int z = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == maxi)
            {
                z++;
                ans = max(ans, z);
            }
            else
                z = 0;
        }
        
        return ans;
    }
};