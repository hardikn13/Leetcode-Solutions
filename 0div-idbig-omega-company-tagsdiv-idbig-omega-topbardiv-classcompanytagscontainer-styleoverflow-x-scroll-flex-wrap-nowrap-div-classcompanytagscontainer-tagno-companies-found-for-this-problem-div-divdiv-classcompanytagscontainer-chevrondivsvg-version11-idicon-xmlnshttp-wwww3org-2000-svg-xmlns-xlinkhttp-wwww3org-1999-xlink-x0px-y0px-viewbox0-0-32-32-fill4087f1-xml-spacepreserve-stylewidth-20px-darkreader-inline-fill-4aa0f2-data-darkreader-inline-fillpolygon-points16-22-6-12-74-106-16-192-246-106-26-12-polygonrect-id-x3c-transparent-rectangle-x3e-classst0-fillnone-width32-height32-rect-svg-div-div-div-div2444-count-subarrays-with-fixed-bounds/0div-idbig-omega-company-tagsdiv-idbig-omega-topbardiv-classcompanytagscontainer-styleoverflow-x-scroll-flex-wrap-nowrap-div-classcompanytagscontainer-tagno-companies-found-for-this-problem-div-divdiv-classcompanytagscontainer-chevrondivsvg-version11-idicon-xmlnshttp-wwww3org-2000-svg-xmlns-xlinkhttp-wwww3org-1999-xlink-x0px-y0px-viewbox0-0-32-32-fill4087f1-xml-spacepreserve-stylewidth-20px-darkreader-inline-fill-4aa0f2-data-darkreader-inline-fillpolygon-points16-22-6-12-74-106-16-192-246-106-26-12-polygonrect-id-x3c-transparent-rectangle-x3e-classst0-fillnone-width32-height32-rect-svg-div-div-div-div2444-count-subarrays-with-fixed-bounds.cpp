class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        int n = nums.size();
        int mini = -1, maxi = -1, bad = -1;
        long long count = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > maxK || nums[i] < minK)
                bad = i;
            
            if(nums[i] == minK)
                mini = i;
            if(nums[i] == maxK)
                maxi = i;
            
            count += max(0, min(maxi, mini) - bad);
        }
        
        return count;
    }
};