class Solution {
public:

    bool static cmp(pair<int, int> &a, pair<int, int> &b)
    {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }

    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
            mp[nums[i]]++;

        vector<pair<int, int>> v;
        for(auto it : mp)
            v.push_back({it.second, it.first});
        
        sort(v.begin(), v.end(), cmp);
        vector<int> ans;
        for(auto it : v)
        {
            int z = it.first;
            while(z)
            {
                ans.push_back(it.second);
                z--;
            }
        }
        
        return ans;
    }
};