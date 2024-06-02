class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        vector<vector<int>> ans;
        for(auto it : firstList)
        {
            for(auto ex : secondList)
            {
                if(it[1] < ex[0])
                    break;
                
                if(ex[1] < it[0])
                    continue;
                
                if(it[0] <= ex[0] && ex[0] <= it[1])
                {
                    ans.push_back({max(it[0], ex[0]), min(ex[1], it[1])});
                }
                else if(ex[0] <= it[0] && it[0] <= it[1])
                {
                    ans.push_back({max(it[0], ex[0]), min(ex[1], it[1])});
                }
            }
        }
        
        return ans;
    }
};