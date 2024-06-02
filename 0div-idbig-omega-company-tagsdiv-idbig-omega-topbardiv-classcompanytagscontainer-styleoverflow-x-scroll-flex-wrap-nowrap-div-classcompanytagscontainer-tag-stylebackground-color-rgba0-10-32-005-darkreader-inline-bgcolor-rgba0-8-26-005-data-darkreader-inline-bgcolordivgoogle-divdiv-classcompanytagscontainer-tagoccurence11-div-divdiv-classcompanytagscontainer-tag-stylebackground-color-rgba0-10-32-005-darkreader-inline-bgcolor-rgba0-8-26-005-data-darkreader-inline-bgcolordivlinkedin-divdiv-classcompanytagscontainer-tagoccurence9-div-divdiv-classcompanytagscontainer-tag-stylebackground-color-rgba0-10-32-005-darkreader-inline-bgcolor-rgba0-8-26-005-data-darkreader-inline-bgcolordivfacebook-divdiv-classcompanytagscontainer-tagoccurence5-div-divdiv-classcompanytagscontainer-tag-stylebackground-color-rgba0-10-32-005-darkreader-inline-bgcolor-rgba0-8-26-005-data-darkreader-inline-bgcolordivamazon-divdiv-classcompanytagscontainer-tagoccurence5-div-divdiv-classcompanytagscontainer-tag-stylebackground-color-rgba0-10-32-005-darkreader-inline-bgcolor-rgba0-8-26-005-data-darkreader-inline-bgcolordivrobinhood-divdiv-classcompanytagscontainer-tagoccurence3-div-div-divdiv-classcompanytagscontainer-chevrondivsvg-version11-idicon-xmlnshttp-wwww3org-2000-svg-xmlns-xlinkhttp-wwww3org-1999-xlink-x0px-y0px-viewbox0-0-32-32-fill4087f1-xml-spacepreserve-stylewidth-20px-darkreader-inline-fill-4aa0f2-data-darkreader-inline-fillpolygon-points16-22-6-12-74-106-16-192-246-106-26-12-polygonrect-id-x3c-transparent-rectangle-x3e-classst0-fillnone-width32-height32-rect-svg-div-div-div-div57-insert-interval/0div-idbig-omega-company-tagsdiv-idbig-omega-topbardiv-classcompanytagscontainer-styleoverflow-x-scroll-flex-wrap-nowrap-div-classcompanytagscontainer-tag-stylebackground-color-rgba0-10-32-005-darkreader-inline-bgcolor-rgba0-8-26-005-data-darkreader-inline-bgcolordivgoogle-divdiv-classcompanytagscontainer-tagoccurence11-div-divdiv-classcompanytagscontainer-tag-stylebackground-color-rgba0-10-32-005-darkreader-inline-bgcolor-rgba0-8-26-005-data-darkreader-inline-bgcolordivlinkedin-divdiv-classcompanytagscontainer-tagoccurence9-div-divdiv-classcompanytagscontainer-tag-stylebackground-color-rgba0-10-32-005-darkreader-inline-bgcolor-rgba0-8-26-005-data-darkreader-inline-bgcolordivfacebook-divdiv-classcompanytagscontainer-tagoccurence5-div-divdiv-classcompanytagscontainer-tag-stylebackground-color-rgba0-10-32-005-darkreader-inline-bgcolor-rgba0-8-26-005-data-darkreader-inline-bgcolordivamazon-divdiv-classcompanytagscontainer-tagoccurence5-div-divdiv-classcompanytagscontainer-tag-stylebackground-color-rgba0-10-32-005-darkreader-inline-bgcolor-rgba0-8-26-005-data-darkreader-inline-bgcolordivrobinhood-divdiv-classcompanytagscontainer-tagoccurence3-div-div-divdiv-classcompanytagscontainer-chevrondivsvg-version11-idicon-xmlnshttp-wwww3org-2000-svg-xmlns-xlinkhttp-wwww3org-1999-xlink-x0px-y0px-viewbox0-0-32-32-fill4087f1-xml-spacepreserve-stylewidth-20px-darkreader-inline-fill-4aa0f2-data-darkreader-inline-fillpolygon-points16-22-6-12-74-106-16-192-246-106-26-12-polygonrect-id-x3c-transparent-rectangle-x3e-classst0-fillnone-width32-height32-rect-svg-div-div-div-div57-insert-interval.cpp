class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> ans;
        int mini = newInterval[0], maxi = newInterval[1];
        for(auto it : intervals)
        {   
            if(mini > it[1])
            {
                ans.push_back({it[0], it[1]});
                continue;
            }
            
            if(maxi >= it[0])
            {
                mini = min(it[0], mini);
                if(maxi < it[1])
                    maxi = it[1];
            }
            else if(it[0] <= mini && mini <= it[1])
            {
                mini = it[0];
                if(maxi < it[1])
                    maxi = it[1];
            }
            else
            {
                ans.push_back({mini, maxi});
                mini = it[0];
                maxi = it[1];
            }
        }
        ans.push_back({mini, maxi});
        return ans;
    }
};