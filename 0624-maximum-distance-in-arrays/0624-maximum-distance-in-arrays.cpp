class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0, mini = 10000, maxi = -10000;
        for(auto &it : arrays)
        {
            ans = max(ans, max(it.back() - mini, maxi - it.front()));
            mini = min(mini, it.front());
            maxi = max(maxi, it.back());
        }
        
        return ans;
    }
};