class Solution {
public:
    int f(int rInd, int kInd, string &ring, string &key, vector<vector<int>> &dp)
    {
        int s = ring.size();
        int t = key.size();
        
        if(kInd == t)
            return 0;

        if(dp[rInd][kInd] != -1)
            return dp[rInd][kInd];
        
        int steps = INT_MAX;
        for(int i = 0; i < s; i++)
        {
            if(ring[i] == key[kInd])
            {
                int diff = abs(rInd - i);
                int step = min(diff, s - diff);
                
                steps = min(steps, step + f(i, kInd + 1, ring, key, dp));
            }
        }

        return dp[rInd][kInd] = steps + 1;
    }
    
    int findRotateSteps(string ring, string key) {
        int s = ring.size();
        int t = key.size();
        
        vector<vector<int>> dp(s, vector<int>(t, -1));
        return f(0, 0, ring, key, dp);
    }
};
