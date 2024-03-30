class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        
        int n = nums.size(), sol = 1e9; 
        for(int i = 0; i < n; i++)
        { 
            int x = 0;

            for(int j = i; j < n; j++)
            { 
                x |= nums[j]; 
                if(x >= k) 
                    sol = min(sol, j - i + 1); 
            } 
        } 
        
        if(sol == 1e9) 
            return -1; 
            
        return sol; 
    }
};
