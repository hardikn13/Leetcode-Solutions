class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];   
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(), pairs.end(), cmp);
        
        int ans = 0, last = INT_MIN;
        for(auto it : pairs)
        {
            if(last < it[0])
            {
                ans++;
                last = it[1];
            }
        }
        
        return ans;
    }
};