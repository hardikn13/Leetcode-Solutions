class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 1;
        int i = 0, j = 0;
        int num = 0;
        
        while(j < n)
        {
            while(num & nums[j])
            {
                num ^= nums[i];
                i++;
            }
            
            num |= nums[j];
            ans = max(ans, j - i + 1);
            
            j++;
        }
        
        return ans;
    }
};