class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto it: mp)
        {
            if(it.second > 2)
                return false;
        }
        
        return true;
    }
};