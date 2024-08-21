class Solution {
public:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if(i == s1.size())
        {
            int z = 0;
            while(j != s2.size())
            {
                z += int(s2[j]);
                j++;
            }

            return z;
        }
        else if(j == s2.size())
        {
            int z = 0;
            while(i != s1.size())
            {
                z += int(s1[i]);
                i++;
            }

            return z;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        if(s1[i] == s2[j])
            ans = f(i + 1, j + 1, s1, s2, dp);
        else
            ans = min(int(s1[i]) + f(i + 1, j, s1, s2, dp), int(s2[j]) + f(i, j + 1, s1, s2, dp));

        return dp[i][j] = ans;
    }

    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return f(0, 0, s1, s2, dp);
    }
};