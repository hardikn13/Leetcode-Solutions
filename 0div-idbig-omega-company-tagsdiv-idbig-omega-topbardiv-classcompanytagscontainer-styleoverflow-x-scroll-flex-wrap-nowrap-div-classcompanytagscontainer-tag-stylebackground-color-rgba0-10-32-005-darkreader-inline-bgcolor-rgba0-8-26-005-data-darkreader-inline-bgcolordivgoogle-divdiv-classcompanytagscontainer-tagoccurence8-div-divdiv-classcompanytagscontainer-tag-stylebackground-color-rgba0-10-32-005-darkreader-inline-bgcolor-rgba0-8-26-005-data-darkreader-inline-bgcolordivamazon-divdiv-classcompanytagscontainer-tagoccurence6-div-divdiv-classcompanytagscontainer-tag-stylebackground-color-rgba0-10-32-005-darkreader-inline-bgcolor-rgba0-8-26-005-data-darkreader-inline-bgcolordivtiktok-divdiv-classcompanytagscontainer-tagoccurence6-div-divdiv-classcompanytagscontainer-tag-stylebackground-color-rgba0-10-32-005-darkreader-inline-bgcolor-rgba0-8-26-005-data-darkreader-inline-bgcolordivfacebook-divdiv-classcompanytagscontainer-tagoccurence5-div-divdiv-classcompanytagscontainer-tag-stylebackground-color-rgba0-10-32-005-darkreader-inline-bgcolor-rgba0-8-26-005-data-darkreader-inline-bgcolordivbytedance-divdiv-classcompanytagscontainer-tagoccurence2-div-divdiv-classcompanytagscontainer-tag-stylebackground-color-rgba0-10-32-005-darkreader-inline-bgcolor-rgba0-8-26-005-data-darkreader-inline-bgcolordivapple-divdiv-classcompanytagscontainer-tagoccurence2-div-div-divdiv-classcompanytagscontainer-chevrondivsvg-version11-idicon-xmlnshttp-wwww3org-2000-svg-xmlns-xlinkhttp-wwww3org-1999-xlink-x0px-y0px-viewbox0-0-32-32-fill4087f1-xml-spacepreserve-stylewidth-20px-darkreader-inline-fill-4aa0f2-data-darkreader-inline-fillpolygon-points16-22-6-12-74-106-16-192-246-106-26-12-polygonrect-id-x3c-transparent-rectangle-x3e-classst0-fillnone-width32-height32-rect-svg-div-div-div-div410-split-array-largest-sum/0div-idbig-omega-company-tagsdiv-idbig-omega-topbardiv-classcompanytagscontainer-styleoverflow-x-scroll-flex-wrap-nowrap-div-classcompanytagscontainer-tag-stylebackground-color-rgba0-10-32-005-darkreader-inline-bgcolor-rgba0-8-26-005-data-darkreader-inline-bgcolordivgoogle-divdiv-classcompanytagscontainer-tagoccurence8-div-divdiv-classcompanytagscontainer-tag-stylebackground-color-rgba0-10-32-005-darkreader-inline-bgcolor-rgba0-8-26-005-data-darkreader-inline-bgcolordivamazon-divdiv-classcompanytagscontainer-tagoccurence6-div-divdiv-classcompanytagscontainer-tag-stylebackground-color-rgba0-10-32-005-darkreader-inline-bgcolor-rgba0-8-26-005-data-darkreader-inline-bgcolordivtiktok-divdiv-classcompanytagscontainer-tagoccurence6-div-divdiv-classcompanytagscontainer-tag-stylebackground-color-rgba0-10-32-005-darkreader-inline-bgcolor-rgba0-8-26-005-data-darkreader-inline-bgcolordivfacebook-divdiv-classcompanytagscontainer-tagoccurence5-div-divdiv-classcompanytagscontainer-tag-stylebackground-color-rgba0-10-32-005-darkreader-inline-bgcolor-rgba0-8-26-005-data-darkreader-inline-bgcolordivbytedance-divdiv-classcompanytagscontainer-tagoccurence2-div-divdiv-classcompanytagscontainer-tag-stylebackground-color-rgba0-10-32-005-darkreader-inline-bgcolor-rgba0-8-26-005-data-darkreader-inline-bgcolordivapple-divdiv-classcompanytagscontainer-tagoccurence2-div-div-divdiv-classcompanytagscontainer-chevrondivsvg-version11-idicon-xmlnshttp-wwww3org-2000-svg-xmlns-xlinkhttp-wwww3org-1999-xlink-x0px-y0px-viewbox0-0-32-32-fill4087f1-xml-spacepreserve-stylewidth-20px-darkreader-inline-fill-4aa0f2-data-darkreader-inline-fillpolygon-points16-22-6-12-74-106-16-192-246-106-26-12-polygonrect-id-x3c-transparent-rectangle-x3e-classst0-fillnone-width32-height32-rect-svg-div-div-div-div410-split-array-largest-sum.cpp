class Solution {
public:
    
    int f(int mid, vector<int>& nums)
    {
        int sum = 0, cnt = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(sum + nums[i] <= mid)
                sum += nums[i];
            else
            {
                cnt++;
                sum = nums[i];
            }
        }
        
        return cnt;
    }
    
    int splitArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        
        while(low <= high)
        {
            int mid = (low + high) / 2;
            
            if(f(mid, nums) > k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return low;
    }
};