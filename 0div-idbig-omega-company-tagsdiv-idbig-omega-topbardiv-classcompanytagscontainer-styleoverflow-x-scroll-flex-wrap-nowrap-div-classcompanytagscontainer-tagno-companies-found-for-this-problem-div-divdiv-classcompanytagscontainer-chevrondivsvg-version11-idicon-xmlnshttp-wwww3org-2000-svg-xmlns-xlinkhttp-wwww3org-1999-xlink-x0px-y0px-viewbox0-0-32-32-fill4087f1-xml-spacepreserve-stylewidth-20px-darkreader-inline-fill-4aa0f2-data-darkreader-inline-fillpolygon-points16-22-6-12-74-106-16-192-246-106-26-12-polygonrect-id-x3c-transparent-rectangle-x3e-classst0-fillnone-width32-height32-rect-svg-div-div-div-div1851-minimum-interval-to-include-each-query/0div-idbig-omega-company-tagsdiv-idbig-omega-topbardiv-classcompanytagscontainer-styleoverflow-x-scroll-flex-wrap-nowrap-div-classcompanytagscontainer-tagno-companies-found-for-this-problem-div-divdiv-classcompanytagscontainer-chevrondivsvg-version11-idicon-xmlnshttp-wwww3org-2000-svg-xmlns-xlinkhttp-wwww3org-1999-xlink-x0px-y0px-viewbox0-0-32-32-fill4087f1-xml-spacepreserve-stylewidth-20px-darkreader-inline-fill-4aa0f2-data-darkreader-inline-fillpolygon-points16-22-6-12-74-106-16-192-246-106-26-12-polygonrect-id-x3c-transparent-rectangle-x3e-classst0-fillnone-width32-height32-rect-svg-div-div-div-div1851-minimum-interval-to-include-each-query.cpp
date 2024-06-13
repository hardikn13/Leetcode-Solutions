class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        
        int n = queries.size();
        map<int, set<pair<int, int>>> mp;
        
        for(auto it : intervals)
        {
            int range = it[1] - it[0] + 1;
            mp[it[0]].insert({-1, range});
            mp[it[1] + 1].insert({1, range});
        }
        
        for(int i = 0; i < n; i++)
            mp[queries[i]].insert({2, i});
        
        vector<int> ans(n, -1);
        multiset<int> sizes;
        
        for(auto& [x, intervals] : mp)
        {
            for(auto& it : intervals)
            {
                if(it.first == -1)
                    sizes.insert(it.second);
                else if(it.first == 1)
                    sizes.erase(sizes.lower_bound(it.second));
                else if(it.first == 2 && !sizes.empty())
                    ans[it.second] = *(sizes.begin());
            }
            
        }
        
        return ans;
    }
};