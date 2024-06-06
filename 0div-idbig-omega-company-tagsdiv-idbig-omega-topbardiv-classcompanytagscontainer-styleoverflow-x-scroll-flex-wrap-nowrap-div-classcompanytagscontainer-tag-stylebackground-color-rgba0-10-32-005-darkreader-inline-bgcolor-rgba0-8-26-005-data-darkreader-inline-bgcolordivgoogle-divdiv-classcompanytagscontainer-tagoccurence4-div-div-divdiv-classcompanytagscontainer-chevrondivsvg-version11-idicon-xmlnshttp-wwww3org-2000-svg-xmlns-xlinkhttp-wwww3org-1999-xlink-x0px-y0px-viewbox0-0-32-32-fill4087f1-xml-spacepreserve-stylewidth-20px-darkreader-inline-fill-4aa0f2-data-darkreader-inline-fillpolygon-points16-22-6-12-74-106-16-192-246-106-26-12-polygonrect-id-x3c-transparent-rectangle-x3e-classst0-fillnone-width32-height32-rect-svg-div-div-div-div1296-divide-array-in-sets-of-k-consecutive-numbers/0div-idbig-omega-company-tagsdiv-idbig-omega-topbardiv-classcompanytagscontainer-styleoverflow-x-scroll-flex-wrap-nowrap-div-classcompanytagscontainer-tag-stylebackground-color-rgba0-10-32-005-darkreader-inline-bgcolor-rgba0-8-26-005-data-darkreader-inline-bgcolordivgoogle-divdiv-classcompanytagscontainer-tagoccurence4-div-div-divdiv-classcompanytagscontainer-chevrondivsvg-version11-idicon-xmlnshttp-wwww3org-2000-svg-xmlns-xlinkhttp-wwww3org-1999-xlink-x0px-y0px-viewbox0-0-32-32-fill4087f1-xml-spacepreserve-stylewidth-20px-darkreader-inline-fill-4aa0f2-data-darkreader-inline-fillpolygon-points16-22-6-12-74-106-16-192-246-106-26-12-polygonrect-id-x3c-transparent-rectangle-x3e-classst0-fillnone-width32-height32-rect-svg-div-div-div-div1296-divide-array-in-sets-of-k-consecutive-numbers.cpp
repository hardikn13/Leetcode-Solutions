class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        if(n % k != 0)
            return false;
        
        map<int, int> mp;
        for(auto it : nums)
            mp[it]++;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++)
        {
            if(mp[nums[i]] == 0)
                continue;
            else
            {
                for(int j = 0; j < k; j++)
                {
                    int here = nums[i] + j;
                    
                    if(mp[here] == 0)
                        return false;
                    
                    mp[here]--;
                }
            }
        }
        
        return true;
    }
};