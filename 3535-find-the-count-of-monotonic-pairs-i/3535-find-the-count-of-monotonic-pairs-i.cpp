class Solution {
public:
    int mod = 1e9 + 7;
    int f(int ind, int prev1, int prev2, vector<int> &nums, vector<vector<vector<int>>> &dp)
    {
        int n = nums.size();
        if(ind == n)
            return 1;

        if(dp[ind][prev1][prev2] != -1)
            return dp[ind][prev1][prev2];

        int ans = 0;
        for(int i = 0; i <= nums[ind]; i++)
        {
            if(prev1 == 0 || i >= prev1)
            {
                if(prev2 >= nums[ind] - i || prev2 == 52)
                    ans = (ans + f(ind + 1, i, nums[ind] - i, nums, dp)) % mod;
            }
        }

        return dp[ind][prev1][prev2] = ans;
    }

    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(54, vector<int>(54, -1)));
        return f(0, 0, 52, nums, dp);
    }
};