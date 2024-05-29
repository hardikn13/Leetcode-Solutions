class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        
        int n = nums.size(), ans = 0;
        for(int i = 0; i < 32; i++)
        {
            int cnt0 = 0;
            int cnt1 = 0;
            int num = 0;
            
            for(int j = 0; j < n; j++)
            {
                if(nums[j] & 1)
                    cnt1++;
                else
                    cnt0++;
                
                if(nums[j] == 0)
                    num++;
                
                nums[j] /= 2;
            }
            
            ans += (cnt0 * cnt1);
            
            if(num == n)
                break;
        }
        
        return ans;
    }
};