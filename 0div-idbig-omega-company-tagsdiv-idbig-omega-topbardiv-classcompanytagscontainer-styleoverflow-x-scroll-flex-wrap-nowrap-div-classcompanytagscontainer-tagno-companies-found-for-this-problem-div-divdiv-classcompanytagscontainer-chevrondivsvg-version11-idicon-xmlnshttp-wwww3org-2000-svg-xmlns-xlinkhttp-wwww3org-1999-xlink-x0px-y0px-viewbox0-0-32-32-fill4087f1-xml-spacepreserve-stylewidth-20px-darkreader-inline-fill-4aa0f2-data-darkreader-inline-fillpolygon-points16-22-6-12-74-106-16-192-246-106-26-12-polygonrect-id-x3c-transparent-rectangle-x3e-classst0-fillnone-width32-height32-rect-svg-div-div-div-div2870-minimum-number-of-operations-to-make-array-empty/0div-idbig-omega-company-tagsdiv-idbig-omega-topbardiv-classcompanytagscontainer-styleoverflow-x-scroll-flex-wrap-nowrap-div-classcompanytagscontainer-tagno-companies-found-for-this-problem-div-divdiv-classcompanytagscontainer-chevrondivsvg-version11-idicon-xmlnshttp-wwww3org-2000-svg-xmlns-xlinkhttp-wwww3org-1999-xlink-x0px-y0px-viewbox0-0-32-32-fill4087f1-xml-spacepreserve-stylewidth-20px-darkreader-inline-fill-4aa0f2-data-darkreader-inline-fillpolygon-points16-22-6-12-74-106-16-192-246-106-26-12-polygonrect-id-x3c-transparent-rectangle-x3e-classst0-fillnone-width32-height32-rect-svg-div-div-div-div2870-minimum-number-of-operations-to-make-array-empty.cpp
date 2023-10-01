class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size();
        map<int, int> mp;
        
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        
        int ans = 0;
        for(auto it : mp)
        {
            while(it.second > 0)
            {
            if(it.second == 1)
                return -1;
            else if(it.second == 2 || it.second == 4)
            {
                it.second -= 2;
                ans++;
            }
            else
            {
                it.second -= 3;
                ans++;
            }
            }
        }
        
        return ans;
    }
};