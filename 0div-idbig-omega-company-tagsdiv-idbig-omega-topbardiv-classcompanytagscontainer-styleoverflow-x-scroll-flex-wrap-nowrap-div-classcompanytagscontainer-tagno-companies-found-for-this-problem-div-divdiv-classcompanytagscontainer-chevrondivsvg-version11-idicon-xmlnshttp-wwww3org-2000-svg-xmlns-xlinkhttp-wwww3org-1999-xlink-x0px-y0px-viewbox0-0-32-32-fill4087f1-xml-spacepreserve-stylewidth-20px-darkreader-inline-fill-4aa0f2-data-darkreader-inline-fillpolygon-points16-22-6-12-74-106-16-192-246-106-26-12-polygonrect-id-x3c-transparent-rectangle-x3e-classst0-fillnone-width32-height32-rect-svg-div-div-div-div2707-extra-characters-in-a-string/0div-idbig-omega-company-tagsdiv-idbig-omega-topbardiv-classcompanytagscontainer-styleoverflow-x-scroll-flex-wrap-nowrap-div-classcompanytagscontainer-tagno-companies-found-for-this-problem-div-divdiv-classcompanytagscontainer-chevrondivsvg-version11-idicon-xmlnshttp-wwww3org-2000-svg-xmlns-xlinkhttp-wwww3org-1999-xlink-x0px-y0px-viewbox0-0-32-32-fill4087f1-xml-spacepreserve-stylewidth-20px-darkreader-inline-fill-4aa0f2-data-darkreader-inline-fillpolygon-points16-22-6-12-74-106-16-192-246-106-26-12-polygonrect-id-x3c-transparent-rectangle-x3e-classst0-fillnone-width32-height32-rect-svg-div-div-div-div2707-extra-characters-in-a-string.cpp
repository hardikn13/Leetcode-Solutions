class Solution {
public:
    int f(int ind, int n, string &s, unordered_map<string, int> &mp, vector<int> &dp)
    {
        if(ind >= n)
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        string temp = "";
        int minExtra = n;
        
        for(int l = ind; l < n; l++)
        {
            int currExtra = 0;
            temp.push_back(s[l]);
            
            if(mp.find(temp) == mp.end())
            {
                currExtra = temp.size();
            }
            
            int remainingExtra = f(l + 1, n, s, mp, dp);
            int totalExtra = currExtra + remainingExtra;
            minExtra = min(minExtra, totalExtra);
        }
        
        return dp[ind] = minExtra;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        
        vector<int> dp(s.size() + 1, -1);
        unordered_map<string, int> mp;
        for(auto it : dictionary)
            mp[it]++;
        
        return f(0, s.size(), s, mp, dp);
    }
};