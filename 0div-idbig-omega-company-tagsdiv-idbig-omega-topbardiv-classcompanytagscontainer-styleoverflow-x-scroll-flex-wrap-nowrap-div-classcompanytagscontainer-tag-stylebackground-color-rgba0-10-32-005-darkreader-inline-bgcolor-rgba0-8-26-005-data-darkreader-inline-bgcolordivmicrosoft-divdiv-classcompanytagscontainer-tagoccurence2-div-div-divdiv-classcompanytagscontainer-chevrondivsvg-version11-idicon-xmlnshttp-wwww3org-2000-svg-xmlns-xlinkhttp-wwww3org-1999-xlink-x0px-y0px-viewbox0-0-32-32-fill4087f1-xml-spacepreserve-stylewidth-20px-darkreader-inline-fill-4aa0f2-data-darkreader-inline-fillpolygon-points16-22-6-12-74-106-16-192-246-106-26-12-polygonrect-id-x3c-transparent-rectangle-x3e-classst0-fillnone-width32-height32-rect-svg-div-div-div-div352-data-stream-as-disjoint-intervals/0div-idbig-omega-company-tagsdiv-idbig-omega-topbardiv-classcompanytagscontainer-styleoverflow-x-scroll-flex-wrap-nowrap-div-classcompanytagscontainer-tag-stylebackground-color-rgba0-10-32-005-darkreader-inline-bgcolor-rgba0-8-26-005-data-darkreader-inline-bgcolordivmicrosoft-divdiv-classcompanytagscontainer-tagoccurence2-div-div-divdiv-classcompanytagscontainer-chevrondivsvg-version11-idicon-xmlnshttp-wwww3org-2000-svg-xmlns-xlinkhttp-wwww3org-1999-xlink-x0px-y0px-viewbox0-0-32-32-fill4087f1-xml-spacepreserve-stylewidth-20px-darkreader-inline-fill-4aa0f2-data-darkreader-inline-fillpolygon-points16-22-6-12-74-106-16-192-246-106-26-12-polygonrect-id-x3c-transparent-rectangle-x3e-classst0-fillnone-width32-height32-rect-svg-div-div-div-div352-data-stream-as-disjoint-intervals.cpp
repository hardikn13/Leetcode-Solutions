class SummaryRanges {
public:
    set<int> st;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        if(st.empty())
            return ans;
        
        int mini = INT_MAX;
        for(auto it : st)
        {
            mini = min(mini, it);
            if(st.count(it + 1))
                continue;
            else
            {
                ans.push_back({mini, it});
                mini = INT_MAX;
            }
        }
        
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */