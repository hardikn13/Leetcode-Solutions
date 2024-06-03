class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        
        map<int, int> mp;
        for(int i = 0; i < n; i++)
            mp[intervals[i][0]] = i;
        
        vector<int> ans(n, -1);
        
        for(int i = 0; i < n; i++)
        {
            int end = intervals[i][1];
            auto lb = mp.lower_bound(end);
            
            if(lb != mp.end())
                ans[i] = lb -> second;
        }
        
        return ans;
    }
};