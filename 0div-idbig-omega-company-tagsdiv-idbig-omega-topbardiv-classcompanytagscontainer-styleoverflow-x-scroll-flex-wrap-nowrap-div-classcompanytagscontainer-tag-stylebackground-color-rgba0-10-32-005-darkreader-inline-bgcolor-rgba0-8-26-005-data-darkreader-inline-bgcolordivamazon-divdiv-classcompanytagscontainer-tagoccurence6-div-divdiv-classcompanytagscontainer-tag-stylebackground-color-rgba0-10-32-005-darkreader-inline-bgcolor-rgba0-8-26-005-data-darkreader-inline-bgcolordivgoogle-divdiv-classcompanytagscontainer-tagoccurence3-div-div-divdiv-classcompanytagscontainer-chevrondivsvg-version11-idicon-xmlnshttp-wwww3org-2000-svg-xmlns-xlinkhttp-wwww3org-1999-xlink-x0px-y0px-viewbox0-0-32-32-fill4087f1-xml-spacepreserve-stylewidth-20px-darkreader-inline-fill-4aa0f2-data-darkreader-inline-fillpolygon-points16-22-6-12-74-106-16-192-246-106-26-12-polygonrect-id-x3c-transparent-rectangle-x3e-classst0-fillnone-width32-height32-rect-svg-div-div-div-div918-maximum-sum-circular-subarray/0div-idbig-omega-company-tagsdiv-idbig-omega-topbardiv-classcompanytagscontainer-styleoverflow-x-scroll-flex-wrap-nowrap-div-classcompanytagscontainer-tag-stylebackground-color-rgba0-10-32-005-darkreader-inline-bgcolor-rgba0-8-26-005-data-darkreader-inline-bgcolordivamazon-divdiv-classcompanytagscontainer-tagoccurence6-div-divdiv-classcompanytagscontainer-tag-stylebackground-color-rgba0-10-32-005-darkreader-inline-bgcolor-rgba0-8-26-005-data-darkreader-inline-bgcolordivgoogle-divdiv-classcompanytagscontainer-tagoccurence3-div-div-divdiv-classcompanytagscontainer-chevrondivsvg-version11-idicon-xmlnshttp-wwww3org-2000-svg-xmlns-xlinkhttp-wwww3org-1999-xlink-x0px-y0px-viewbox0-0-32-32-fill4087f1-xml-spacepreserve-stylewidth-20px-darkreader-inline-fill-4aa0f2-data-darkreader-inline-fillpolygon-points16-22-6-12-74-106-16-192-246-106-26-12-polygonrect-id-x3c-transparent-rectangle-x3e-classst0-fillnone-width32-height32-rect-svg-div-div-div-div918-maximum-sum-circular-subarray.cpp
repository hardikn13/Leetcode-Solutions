class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n = nums.size();
        int kadane = INT_MIN, sum = 0, totalSum = 0;
        for(int i = 0; i < n; i++)
        {
            totalSum += nums[i];
            sum += nums[i];
            
            kadane = max(kadane, sum);
            
            if(sum < 0)
                sum = 0;
        }
        
        int reverseKadane = INT_MAX;
        sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            
            reverseKadane = min(reverseKadane, sum);
            
            if(sum > 0)
                sum = 0;
        }
        
        if(totalSum - reverseKadane == 0)
            return kadane;
        
        int ans = max(kadane, totalSum - reverseKadane);
        
        return ans;
    }
};