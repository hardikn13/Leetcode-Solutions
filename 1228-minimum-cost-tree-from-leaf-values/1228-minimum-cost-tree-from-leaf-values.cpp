class Solution {
public:
    int f(int i, int j, map<pair<int, int>, int> &mp, vector<vector<int>> &dp)
    {
        if(i == j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        for(int ind = i; ind < j; ind++)
            ans = min(ans, mp[{i, ind}] * mp[{ind + 1, j}] + f(i, ind, mp, dp) + f(ind + 1, j, mp, dp));

        return dp[i][j] = ans;
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        map<pair<int, int>, int> mp;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        for(int i = 0; i < n; i++)
        {
            mp[{i, i}] = arr[i];
            for(int j = i + 1; j < n; j++)
                mp[{i, j}] = max(arr[j], mp[{i, j - 1}]);
        }

        return f(0, n - 1, mp, dp);
    }
};