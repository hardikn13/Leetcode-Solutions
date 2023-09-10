class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        
        unordered_set<int> st;
        
        for(auto it : nums)
        {
            int start = it[0], end = it[1];
            for(int i = start; i <= end; i++)
            {
                st.insert(i);
            }
        }
        
        return st.size();
    }
};