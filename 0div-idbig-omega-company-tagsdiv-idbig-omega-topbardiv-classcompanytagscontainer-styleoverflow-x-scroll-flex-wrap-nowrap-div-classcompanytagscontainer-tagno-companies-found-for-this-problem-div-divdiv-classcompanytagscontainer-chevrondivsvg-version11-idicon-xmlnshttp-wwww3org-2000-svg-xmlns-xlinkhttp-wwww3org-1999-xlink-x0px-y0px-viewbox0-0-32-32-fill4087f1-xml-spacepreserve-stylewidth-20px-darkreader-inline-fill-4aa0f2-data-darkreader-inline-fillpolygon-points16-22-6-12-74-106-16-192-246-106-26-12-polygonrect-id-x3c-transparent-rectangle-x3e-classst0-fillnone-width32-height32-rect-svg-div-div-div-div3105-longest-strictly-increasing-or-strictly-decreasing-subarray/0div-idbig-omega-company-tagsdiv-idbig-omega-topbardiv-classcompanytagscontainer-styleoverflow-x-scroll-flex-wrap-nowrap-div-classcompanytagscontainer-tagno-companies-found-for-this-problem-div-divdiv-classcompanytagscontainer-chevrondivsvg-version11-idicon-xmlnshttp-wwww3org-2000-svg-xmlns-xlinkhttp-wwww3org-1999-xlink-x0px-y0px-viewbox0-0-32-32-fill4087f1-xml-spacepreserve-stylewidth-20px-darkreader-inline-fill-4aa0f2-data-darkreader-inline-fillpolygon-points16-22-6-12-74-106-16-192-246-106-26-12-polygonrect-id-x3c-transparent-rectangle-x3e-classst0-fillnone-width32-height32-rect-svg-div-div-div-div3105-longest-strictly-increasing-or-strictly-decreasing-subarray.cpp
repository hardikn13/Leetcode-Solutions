class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int z = -1;
        
        if(n ==  1)
            return 1;
        
        
        int cnt = 1, ans = 1;
        for(int i = 0; i < n - 1; i++)
        {
            if(z == -1)
            {
                if(nums[i] < nums[i + 1])
                    z = 0;
                else if(nums[i] > nums[i + 1])
                    z = 1;
                else z = -1;
            }
            
            if(nums[i] < nums[i + 1] && z == 1)
            {
                cnt++;
            }
            else if(nums[i] < nums[i + 1] && z == 0)
            {
                cnt = 2;
                z = 1;
            }
            else if(nums[i] > nums[i + 1] && z == 0)
            {
                cnt++;
            }
            else if(nums[i] > nums[i + 1] && z == 1)
            {
                cnt = 2;
                z = 0;
            }
            else
            {
                cnt = 0;
                z = -1;
            }
            
            ans = max(ans, cnt);
        }
        
        return ans;
    }
};