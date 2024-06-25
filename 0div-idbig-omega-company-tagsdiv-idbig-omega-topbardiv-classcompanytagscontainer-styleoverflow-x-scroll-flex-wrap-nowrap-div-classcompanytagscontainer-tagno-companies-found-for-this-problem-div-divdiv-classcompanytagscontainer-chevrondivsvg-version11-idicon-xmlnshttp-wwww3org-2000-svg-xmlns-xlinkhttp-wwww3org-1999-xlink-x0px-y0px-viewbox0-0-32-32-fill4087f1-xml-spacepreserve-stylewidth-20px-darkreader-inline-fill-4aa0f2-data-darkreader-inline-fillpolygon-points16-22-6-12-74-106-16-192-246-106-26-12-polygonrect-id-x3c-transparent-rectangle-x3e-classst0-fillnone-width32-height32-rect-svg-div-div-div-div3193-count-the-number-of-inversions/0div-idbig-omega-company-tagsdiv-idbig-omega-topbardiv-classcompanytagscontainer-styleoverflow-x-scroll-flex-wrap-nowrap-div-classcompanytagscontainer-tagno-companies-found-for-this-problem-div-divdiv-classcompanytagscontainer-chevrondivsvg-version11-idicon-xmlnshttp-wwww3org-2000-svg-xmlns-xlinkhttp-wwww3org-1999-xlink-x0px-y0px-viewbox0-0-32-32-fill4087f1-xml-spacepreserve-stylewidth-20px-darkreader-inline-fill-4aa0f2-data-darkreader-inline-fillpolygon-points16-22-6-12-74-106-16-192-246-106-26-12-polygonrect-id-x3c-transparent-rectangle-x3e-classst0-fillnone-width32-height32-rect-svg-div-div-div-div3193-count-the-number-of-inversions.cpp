class Solution {
public:
    int mod = 1e9 + 7;
    int f(int pref, int ind, int cnt, vector<vector<int>> &req, vector<vector<int>> &dp)
    {   
        if(ind >= 0 && req[ind][0] == pref)
        {
            if(req[ind][1] != cnt)
                return 0;
            
            ind--;
        }
        
        if(pref == 0)
            return cnt == 0;
        
        if(dp[pref][cnt] != -1)
            return dp[pref][cnt];
        
        int ans = 0;
        for(int k = 0; k <= min(pref, cnt); k++)
            ans = (ans + f(pref - 1, ind, cnt - k, req, dp)) % mod;
        
        return dp[pref][cnt] = ans;
    }
    
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        vector<vector<int>> dp(n + 1, vector<int> (401, -1));
        sort(requirements.begin(), requirements.end());
        return f(n - 1, requirements.size() - 1, requirements.back()[1], requirements, dp);
    }
};