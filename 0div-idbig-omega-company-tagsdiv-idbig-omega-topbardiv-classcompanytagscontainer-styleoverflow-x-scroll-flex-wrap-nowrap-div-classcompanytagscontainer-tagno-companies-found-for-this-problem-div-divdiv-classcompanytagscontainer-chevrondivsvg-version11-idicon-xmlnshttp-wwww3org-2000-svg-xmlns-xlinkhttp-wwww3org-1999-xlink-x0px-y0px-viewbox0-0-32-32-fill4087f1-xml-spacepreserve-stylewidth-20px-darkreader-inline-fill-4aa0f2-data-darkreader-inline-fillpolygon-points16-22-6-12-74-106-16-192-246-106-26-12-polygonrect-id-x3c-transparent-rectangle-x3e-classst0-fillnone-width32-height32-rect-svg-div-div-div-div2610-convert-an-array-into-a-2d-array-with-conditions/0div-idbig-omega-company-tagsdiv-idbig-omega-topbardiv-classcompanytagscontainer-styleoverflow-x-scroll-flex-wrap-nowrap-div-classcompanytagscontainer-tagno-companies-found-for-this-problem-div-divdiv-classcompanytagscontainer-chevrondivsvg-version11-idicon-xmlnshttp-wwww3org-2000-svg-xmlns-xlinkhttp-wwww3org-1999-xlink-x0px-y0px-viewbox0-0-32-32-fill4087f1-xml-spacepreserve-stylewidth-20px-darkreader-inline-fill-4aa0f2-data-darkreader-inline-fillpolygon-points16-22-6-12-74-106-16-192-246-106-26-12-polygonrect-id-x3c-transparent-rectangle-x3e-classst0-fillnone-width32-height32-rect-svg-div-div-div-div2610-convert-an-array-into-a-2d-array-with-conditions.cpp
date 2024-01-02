class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        int n = nums.size(), maxi = 0;
        
        map<int, int> mp;
        for(auto num : nums)
        {
            mp[num]++;
            maxi = max(mp[num], maxi);
        }
        
        vector<vector<int>> ans(maxi);
        
        for(auto it : mp)
        {
            for(int i = 0; i < it.second; i++)
            {
                ans[i].push_back(it.first);
            }
        }
        
        return ans;
    }
};