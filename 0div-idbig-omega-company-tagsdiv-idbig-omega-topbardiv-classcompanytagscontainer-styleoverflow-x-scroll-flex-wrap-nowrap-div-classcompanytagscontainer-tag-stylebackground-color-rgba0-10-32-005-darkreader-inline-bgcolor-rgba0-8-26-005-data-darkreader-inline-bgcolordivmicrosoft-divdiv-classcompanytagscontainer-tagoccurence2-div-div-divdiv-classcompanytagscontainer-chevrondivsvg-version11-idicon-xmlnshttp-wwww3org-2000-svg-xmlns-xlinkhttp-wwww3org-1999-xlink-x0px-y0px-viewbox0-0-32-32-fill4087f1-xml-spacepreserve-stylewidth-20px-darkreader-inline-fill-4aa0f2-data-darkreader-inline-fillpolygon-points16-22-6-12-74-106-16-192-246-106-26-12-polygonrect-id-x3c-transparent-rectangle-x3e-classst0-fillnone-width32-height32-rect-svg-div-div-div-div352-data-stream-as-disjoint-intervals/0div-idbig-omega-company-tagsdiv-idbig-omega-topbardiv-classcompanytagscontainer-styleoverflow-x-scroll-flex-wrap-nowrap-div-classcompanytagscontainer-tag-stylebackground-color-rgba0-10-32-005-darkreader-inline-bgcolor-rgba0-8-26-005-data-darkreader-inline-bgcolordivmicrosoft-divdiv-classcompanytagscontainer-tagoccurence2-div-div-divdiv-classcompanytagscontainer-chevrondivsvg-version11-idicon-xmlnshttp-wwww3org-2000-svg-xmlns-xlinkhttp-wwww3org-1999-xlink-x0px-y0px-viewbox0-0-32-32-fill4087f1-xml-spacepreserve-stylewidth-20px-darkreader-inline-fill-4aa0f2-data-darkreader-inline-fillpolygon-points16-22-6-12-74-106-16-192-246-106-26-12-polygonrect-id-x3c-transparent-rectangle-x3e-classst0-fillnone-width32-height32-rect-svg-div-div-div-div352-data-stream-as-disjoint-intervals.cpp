class SummaryRanges {
public:
    map<int, int> mp;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        int left = value;
        int right = value;
        
        auto it = mp.upper_bound(value);
        
        if(it != mp.begin())
        {
            auto before = it;
            before--;
            
            if(before -> second >= value)
                return;
            
            if(before -> second == value - 1)
                left = before -> first;
        }
        
        if(it != mp.end() && it -> first == right + 1)
        {
            right = it -> second;
            mp.erase(it);
        }
        
        mp[left] = right;
    }
    
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        
        for(auto it : mp)
            ans.push_back({it.first, it.second});
            
        return ans;
    }
};




// ANOTHER APPROACH
// ----------------
// class SummaryRanges {
// public:
//     set<int> st;
//     SummaryRanges() {
        
//     }
    
//     void addNum(int value) {
//         st.insert(value);
//     }
    
//     vector<vector<int>> getIntervals() {
//         vector<vector<int>> ans;
//         if(st.empty())
//             return ans;
        
//         int mini = INT_MAX;
//         for(auto it : st)
//         {
//             mini = min(mini, it);
//             if(st.count(it + 1))
//                 continue;
//             else
//             {
//                 ans.push_back({mini, it});
//                 mini = INT_MAX;
//             }
//         }
        
//         return ans;
//     }
// };

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */