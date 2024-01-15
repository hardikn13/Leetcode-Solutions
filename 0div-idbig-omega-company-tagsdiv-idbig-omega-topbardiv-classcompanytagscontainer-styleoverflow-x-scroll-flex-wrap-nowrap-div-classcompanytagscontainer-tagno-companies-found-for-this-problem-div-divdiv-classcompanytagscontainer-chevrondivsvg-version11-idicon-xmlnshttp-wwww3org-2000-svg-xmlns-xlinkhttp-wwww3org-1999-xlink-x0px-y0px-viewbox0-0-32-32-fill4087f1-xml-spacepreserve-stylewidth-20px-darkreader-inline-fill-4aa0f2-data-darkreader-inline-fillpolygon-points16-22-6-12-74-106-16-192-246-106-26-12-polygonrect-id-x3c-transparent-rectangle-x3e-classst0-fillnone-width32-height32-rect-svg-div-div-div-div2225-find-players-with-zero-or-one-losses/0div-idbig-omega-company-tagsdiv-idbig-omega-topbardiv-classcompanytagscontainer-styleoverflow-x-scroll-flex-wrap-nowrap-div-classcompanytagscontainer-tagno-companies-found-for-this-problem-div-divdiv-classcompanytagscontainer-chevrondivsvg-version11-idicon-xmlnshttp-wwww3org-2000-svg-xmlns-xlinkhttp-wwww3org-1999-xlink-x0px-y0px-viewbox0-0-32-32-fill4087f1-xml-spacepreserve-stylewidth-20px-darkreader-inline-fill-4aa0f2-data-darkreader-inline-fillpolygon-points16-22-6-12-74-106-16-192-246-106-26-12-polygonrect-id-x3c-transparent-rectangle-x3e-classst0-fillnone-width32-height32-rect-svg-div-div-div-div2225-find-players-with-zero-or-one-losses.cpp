class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        vector<vector<int>> ans(2);
        unordered_map<int, int> mp;
        set<int> st;
        
        for(auto it : matches)
        {
            st.insert(it[0]);
        }
        
        for(auto it : matches)
        {
            mp[it[1]]++;
        }
        
        for(auto it : st)
        {
            if(mp.find(it) == mp.end())
                ans[0].push_back(it);
        }
        
        for(auto it : mp)
        {
            if(it.second == 1)
                ans[1].push_back(it.first);
        }
        
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        
        return ans;
    }
};