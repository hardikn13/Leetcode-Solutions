class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();
        int cnt = 1, maxi = 1, z = 0;
        
        if(n == 1)
            if(nums[0] == 1)
                return 1;
        
        for(int i = 0; i < n - 1; i++)
        {
            if(nums[i] == 1 && nums[i + 1] == 1)
            {
                cnt++;
                maxi = max(cnt, maxi);
            }
            else
                cnt = 1;
            
            if(nums[i] == 1 || nums[i + 1] == 1)
                z = 1;
        }
        
        if(z == 0)
            return 0;
        
        return maxi;
    }
};