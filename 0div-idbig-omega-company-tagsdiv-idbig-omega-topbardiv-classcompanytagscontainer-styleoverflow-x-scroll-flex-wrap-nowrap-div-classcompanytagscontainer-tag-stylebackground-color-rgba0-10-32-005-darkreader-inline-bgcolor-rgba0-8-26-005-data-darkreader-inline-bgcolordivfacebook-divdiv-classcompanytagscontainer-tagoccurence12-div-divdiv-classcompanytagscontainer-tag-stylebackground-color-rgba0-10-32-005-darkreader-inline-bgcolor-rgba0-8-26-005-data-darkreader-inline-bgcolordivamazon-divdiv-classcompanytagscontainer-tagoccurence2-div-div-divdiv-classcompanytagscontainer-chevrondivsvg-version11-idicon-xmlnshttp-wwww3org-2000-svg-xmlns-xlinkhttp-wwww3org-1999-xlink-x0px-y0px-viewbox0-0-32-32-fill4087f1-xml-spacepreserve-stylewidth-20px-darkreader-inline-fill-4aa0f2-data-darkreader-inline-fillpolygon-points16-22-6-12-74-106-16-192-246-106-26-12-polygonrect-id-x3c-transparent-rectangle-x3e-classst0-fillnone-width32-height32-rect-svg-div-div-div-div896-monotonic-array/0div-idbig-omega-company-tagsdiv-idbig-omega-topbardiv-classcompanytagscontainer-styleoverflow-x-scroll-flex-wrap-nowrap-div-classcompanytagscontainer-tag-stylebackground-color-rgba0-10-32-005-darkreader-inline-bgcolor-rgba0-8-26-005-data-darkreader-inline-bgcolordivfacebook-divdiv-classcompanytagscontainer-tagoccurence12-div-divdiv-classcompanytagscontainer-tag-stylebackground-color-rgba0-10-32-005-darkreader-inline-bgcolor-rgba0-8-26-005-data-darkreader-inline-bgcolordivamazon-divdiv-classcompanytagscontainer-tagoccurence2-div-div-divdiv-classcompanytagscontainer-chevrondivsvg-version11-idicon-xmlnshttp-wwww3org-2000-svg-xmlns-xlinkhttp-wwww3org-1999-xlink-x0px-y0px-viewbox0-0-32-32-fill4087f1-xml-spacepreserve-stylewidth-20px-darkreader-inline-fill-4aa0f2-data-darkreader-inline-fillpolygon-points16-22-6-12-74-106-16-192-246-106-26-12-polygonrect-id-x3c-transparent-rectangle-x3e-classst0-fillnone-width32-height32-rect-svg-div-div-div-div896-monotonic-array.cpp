class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> v = nums;
        sort(v.begin(), v.end());
        
        bool increase = true;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != v[i])
                increase = false;
        }
        
        bool decrease = true;
        for(int i = n - 1; i >= 0; i--)
        {
            if(nums[i] != v[n - i - 1])
                decrease = false;
        }
        
        return increase || decrease;
    }
};