class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        long long mod = 1e9 + 7;
        int n = nums.size();
        int dp[target + 1];
        dp[0] = 1;
        for(int i = 1; i <= target; i++){
            int comb = 0;
            for(int j = 0; j < n; j++){
                if(nums[j] <= i){
                    comb += dp[i - nums[j]] % mod;
                }
            }
            dp[i] = comb;
        }
        return dp[target];
    }
};