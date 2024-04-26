class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            int cnt = 0, sum = 0;
            for(int j = 1; j * j <= nums[i]; j++)
            {
                if(j * j == nums[i])
                {
                    cnt++;
                    sum += i;
                    break;
                }
                    
                if(nums[i] % j == 0)
                {
                    sum += nums[i] / j;
                    sum += j;
                    cnt += 2;
                }
            }
            
            if(cnt == 4)
                ans += sum;
        }
        
        return ans;
    }
};