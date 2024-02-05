class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        
        int count = 0, ans = 0, n = nums.size(), z = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > 0)
            {
                count += nums[i];
                z = 1;
            }
            else if(nums[i] < 0)
            {
                count += nums[i];
                z = 1;
            }
            
            if(z == 1 && count == 0)
            {
                ans++;
                z = 0;
            }
        }
        
        return ans;
    }
};