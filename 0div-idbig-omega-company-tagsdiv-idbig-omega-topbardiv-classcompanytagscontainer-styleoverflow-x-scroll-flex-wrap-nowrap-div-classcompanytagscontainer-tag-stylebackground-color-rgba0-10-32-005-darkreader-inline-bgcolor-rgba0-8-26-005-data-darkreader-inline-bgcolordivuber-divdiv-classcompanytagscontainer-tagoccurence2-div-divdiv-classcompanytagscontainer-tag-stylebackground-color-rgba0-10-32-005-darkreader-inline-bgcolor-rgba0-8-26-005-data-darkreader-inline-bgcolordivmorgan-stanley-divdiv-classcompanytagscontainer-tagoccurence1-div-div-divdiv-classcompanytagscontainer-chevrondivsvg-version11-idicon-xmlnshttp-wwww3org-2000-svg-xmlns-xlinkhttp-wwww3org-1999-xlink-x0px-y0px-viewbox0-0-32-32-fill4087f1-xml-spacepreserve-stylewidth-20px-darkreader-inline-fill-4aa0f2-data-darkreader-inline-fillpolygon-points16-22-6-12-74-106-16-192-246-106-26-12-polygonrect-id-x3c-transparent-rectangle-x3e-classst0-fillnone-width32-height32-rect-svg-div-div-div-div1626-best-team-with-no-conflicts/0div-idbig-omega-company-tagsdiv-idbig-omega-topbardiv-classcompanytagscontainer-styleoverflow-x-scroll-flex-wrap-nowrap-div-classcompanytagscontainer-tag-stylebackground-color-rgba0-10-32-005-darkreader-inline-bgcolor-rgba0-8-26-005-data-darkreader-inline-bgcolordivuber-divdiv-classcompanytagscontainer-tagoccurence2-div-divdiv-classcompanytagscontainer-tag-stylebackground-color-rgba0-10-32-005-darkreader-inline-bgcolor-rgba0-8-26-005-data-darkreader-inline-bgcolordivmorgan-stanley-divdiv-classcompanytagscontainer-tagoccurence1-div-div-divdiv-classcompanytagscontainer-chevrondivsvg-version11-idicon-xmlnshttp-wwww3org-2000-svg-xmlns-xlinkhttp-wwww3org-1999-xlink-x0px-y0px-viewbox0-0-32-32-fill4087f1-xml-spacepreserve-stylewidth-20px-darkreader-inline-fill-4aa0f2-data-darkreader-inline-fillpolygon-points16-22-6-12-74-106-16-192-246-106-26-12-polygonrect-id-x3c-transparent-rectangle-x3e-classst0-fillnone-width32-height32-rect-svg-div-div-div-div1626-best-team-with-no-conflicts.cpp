class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        int n = scores.size();
        vector<pair<int, int>> v;
        
        for(int i = 0; i < n; i++)
        {
            v.push_back({ages[i], scores[i]});
        }
        sort(v.begin(), v.end());
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        for(int ind = n - 1; ind >= 0; ind--)
        {
            for(int prevInd = ind - 1; prevInd >= -1; prevInd--)
            {
                int notTake = dp[ind + 1][prevInd + 1];
                int take = 0;
                if(prevInd == -1 || v[ind].second >= v[prevInd].second)
                    take = v[ind].second + dp[ind + 1][ind + 1];

                dp[ind][prevInd + 1] = max(take, notTake);
            }
        }
        
        return dp[0][-1 + 1];
    }
};






// MEMOIZATION
// -----------

// int f(int ind, int prevInd, vector<pair<int, int>>& v, vector<vector<int>> &dp)
//     {
//         if(ind >= v.size())
//             return 0;
        
//         if(dp[ind][prevInd + 1] != -1)
//             return dp[ind][prevInd + 1];
        
//         int notTake = f(ind + 1, prevInd, v, dp);
//         int take = 0;
//         if(prevInd == -1 || v[ind].second >= v[prevInd].second)
//             take = v[ind].second + f(ind + 1, ind, v, dp);
            
//         return dp[ind][prevInd + 1] = max(take, notTake);
//     }
    
//     int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
//         int n = scores.size();
//         vector<pair<int, int>> v;
        
//         for(int i = 0; i < n; i++)
//         {
//             v.push_back({ages[i], scores[i]});
//         }
//         sort(v.begin(), v.end());
        
//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        
//         return f(0, -1, v, dp);
//     }