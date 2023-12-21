class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = cost[0];
        int prev = cost[1];
        for(int i = 2; i < n; i++)
        {
            int curr = min(cost[i] + prev, cost[i] + prev2);
            prev2 = prev;
            prev = curr;
        }
        return min(prev, prev2);
    }
};




// MEMOIZATION
// -----------

// class Solution {
// public:
//     int f(int ind, vector<int> cost, vector<int> &dp)
//     {
//         if(ind == 0)
//             return cost[0];
//         if(ind == 1)
//             return cost[1];
        
//         if(dp[ind] != -1)
//             return dp[ind];
        
//         dp[ind] = min(cost[ind] + f(ind - 1, cost, dp), cost[ind] + f(ind - 2, cost, dp));
        
//         return dp[ind];
        
//     }
    
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         vector<int> dp(n + 1, -1);
//         return min(f(n - 1, cost, dp), f(n - 2, cost, dp));
//     }
// };