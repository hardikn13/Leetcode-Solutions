class Solution {
public:
    
    long long f(int divide, vector<int> &nums)
    {
        long long total = 0, n = nums.size();
        for(int i = 0; i < n; i++)
            total += ceil((double)nums[i] / (double)divide);
        
        return total;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int n = nums.size();
        int low = 1, high = *max_element(nums.begin(), nums.end()) + 1;
        
        while(low <= high)
        {
            int mid = (low + high) / 2;
            
            if(f(mid, nums) > threshold)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return low;
    }
};