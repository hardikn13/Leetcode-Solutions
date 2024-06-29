class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        vector<vector<int>> ans;
        set<pair<int, int>> st;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        pq.push({nums1[0] + nums2[0], {0, 0}});
        st.insert({0, 0});
        while(k-- && !pq.empty())
        {
            auto z = pq.top();
            int i = z.second.first;
            int j = z.second.second;
            pq.pop();
            
            ans.push_back({nums1[i], nums2[j]});
            
            if(i + 1 < n1 && st.find({i + 1, j}) == st.end())
            {
                pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                st.insert({i + 1, j});   
            }
            
            if(j + 1 < n2 && st.find({i, j + 1}) == st.end())
            {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                st.insert({i, j + 1});
            }
        }
        
        return ans;
    }
};