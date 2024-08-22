class Solution {
public:
    int f(int i, int j, int k, vector<int>& pref, vector<int>& stones, vector<vector<int>> &dp)
    {
        if(i >= j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        for(int start = i; start < j; start += k - 1)
            ans = min(ans, f(i, start, k, pref, stones, dp) + f(start + 1, j, k, pref, stones, dp));

        if((j - i) % (k - 1) == 0)
            ans += pref[j + 1] - pref[i];

        return dp[i][j] = ans;
    }

    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if((n - 1) % (k - 1))
            return -1;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        vector<int> pref(n + 1, 0);
        for(int i = 0; i < n; i++)
            pref[i + 1] = stones[i] + pref[i];

        return f(0, n - 1, k, pref, stones, dp);
    }
};