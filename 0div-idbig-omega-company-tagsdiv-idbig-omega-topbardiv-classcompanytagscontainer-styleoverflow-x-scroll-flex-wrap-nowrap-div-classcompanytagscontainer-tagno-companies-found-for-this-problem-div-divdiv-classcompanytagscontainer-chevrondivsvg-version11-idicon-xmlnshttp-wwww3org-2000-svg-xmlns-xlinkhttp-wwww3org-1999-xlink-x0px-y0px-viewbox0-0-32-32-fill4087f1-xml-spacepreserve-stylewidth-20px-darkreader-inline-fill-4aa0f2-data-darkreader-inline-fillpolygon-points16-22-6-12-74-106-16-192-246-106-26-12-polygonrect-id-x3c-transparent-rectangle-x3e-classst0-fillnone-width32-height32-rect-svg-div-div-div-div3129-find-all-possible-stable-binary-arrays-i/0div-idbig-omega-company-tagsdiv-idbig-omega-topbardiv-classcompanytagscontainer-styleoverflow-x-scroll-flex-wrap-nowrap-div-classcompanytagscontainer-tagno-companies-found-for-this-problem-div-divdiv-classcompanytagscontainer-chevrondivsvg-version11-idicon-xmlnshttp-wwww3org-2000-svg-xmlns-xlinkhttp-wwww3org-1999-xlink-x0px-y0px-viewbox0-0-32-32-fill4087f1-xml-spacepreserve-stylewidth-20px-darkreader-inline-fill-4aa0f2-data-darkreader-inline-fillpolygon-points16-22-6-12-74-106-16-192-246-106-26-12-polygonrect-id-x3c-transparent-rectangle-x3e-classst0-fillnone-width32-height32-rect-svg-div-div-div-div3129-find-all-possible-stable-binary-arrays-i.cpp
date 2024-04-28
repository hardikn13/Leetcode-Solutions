class Solution {
public:
    int mod = 1e9 + 7;
    long long f(long long zero, long long one, long long consecutive, long long cnt, long long limit, vector<vector<vector<vector<int>>>> &dp)
    {
        if(zero == 0 && one == 0)
            return 1;
        
        if(dp[zero][one][consecutive][cnt] != -1)
            return dp[zero][one][consecutive][cnt];
        
        long long ans = 0;
        
        if(zero > 0)
        {
            if(consecutive == 0 && cnt < limit)
                ans = (ans + f(zero - 1, one, 0, cnt + 1, limit, dp)) % mod;
            else if(consecutive == 1 || consecutive == 2)
                ans = (ans + f(zero - 1, one, 0, 1, limit, dp)) % mod;
        }
        
        if(one > 0)
        {
            if(consecutive == 1 && cnt < limit)
                ans = (ans + f(zero, one - 1, 1, cnt + 1, limit, dp)) % mod;
            else if(consecutive == 0 || consecutive == 2)
                ans = (ans + f(zero, one - 1, 1, 1, limit, dp)) % mod;
        }
        
        
        return dp[zero][one][consecutive][cnt] = ans % mod;
    }
    
    int numberOfStableArrays(int zero, int one, int limit) {
        
        vector<vector<vector<vector<int>>>> dp(zero + 1, vector<vector<vector<int>>> (one + 1, vector<vector<int>> (3, vector<int> (limit + 1, -1))));
        return (int)f(zero, one, 2, 0, limit, dp) % mod;
    }
};
