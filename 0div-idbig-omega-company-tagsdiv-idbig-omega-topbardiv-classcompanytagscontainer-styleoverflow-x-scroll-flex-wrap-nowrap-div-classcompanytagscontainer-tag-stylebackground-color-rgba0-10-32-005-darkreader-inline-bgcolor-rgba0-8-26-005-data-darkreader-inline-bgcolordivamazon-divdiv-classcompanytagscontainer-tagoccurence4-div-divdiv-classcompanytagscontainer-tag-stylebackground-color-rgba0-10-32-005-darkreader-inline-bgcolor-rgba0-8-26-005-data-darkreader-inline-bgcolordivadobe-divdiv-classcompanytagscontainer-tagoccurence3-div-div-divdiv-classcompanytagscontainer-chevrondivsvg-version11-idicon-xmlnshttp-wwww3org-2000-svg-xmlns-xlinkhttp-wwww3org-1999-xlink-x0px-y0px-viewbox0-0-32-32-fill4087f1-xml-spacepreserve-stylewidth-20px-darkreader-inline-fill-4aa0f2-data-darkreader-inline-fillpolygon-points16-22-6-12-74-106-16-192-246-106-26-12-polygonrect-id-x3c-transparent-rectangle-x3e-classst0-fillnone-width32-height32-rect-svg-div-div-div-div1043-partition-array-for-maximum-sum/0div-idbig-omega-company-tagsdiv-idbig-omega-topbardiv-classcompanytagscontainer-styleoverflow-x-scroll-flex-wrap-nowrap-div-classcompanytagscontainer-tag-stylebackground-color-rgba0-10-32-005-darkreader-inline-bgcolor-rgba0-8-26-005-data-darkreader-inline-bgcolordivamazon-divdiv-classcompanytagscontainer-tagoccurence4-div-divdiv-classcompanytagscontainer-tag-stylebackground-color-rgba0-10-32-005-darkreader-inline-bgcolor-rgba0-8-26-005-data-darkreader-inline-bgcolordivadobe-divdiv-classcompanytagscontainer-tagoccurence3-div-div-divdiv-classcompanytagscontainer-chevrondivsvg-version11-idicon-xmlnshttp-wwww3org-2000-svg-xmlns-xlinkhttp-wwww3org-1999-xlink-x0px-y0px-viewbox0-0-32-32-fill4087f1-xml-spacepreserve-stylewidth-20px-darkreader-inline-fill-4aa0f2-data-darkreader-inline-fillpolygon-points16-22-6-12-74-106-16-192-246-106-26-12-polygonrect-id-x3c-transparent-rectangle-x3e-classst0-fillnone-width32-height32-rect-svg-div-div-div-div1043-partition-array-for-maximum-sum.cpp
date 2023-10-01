class Solution {
public:
    
    int f(int ind, int k, int n, vector<int> &arr, vector<int> &dp)
    {
        if(ind == n)
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int len = 0, maxi = INT_MIN, maxAns = INT_MIN;
        for(int j = ind; j < min(n, ind + k); j++)
        {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = len * maxi + f(j + 1, k, n, arr, dp);
            maxAns = max(maxAns, sum);
        }
        
        return dp[ind] = maxAns;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        return f(0, k, n, arr, dp);
    }
};