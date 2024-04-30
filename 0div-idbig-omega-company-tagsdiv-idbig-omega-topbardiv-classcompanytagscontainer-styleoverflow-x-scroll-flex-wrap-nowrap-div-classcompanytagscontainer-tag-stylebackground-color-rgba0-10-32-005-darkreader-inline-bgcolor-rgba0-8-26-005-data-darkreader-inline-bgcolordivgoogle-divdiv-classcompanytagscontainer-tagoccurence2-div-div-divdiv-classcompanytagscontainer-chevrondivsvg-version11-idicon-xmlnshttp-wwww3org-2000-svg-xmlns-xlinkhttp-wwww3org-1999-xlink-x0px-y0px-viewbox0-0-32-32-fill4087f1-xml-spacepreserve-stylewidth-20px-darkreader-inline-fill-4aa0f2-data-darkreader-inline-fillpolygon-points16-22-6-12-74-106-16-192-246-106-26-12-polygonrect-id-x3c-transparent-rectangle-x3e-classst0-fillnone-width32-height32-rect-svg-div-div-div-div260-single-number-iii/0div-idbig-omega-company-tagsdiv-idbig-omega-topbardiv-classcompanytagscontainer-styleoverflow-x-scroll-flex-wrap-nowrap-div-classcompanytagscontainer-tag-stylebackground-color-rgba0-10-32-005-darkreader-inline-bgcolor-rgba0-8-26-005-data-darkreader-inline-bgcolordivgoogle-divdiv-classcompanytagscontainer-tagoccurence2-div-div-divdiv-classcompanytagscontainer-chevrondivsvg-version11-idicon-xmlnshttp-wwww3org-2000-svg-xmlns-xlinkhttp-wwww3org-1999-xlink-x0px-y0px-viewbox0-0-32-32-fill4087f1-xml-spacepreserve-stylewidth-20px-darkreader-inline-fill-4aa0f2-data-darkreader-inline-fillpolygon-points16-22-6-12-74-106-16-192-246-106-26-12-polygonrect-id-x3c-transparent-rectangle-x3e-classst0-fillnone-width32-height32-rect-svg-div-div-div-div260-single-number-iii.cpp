class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int n = nums.size();
        int x = 0;
        
        for(int i = 0; i < n; i++)
        {
            x ^= nums[i];
        }
        
        
        int mask = 1;
        while ((mask & x) == 0)
            mask <<= 1;
        
        int a = 0;
        for(int i = 0; i < n; i++)
        {
            if(mask & nums[i])
                a ^= nums[i];
        }
        
        int b = a ^ x;
        
        return {a, b};
    }
};