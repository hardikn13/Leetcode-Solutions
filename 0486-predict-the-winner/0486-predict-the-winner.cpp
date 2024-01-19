class Solution {
public:
    int f(int i, int j, int turn, vector<int> &nums, vector<vector<vector<long long>>> &dp)
    {
        if(i > j)
            return 0;
        
        if(dp[i][j][turn] != -1)
            return dp[i][j][turn];
        
        if(turn == 0)
            return dp[i][j][turn] = max(nums[i] + f(i + 1, j, 1, nums, dp),
                                        nums[j] + f(i, j - 1, 1, nums, dp));
        else
            return dp[i][j][turn] = min(-nums[i] + f(i + 1, j, 0, nums, dp),
                       -nums[j] + f(i, j - 1, 0, nums, dp));
        
    }
    
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<long long>>>dp(n, vector<vector<long long>>(n,
                                                vector<long long>(2, -1)));
        int ans = f(0, n - 1, 0, nums, dp);
        
        return ans >= 0;
    }
};