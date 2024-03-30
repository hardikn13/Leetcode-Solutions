class Solution {
public:
    int f(vector<int>& nums, int k)
    {
        if(k == 0)
            return 0;
        
        int n = nums.size();
        int total = 0;
        int diff = 0;
        int i = 0;
        int j = 0;
        vector<int> count(20002);
        
        while(j < n)
        {
            if(count[nums[j]] == 0)
            {
                diff++;
                count[nums[j]]++;
            }
            else
            {
                count[nums[j]]++;
            }
            
            if(diff <= k)
            {
                total += j - i + 1;
            }
            else
            {
                while(i < n && i <= j && diff > k)
                {
                    count[nums[i]]--;
                    
                    if(count[nums[i]] == 0)
                        diff--;
                    
                    i++;
                }
                
                total += j - i + 1;
            }
            
            j++;
        }
        
        return total;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k - 1);
    }
};