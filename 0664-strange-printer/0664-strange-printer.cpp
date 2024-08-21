class Solution {
public:
    int f(int low, int high, string &s, vector<vector<int>> &dp)
    {
        if(low > high)
            return 0;

        if(dp[low][high] != -1)
            return dp[low][high];

        int l = low;
        while(low < high && s[low] == s[low + 1])
            low++;

        int ans = 1 + f(low + 1, high, s, dp);

        for(int ind = low + 1; ind <= high; ind++)
        {
            if(s[l] == s[ind])
                ans = min(ans, f(ind, high, s, dp) + f(low + 1, ind - 1, s, dp));
        }

        return dp[l][high] = ans;
    }

    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, n - 1, s, dp);
    }
};