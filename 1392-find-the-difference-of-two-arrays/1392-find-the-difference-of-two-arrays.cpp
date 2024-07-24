class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> st1, st2;

        int n1 = nums1.size(), n2 = nums2.size();
        for(int i = 0; i < n1; i++)
            st1.insert(nums1[i]);
        for(int i = 0; i < n2; i++)
            st2.insert(nums2[i]);

        vector<vector<int>> ans(2);
        for(auto it : st1)
        {
            if(st2.find(it) == st2.end())
                ans[0].push_back(it);
        }
        for(auto it : st2)
        {
            if(st1.find(it) == st1.end())
                ans[1].push_back(it);
        }

        return ans;
    }
};