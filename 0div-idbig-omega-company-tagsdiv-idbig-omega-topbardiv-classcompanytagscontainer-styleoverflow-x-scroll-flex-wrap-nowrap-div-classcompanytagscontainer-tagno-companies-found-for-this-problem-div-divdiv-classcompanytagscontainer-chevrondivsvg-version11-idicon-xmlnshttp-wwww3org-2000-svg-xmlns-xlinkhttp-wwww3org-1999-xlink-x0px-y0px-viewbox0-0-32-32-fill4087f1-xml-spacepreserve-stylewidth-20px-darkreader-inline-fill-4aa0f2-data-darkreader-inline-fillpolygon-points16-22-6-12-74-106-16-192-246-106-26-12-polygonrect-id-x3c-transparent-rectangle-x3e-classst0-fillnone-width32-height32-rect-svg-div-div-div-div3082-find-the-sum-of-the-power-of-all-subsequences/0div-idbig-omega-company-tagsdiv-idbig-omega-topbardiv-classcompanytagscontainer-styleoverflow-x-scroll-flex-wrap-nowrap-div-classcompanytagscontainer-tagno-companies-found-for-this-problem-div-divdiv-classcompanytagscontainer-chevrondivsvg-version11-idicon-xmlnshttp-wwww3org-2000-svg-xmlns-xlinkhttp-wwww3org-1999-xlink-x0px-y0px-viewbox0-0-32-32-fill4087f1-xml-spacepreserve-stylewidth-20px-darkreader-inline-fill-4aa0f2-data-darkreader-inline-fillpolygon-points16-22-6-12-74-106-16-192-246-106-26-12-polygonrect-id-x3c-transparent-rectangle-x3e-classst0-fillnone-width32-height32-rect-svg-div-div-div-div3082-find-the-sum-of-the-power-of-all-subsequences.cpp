class Solution {
public:
    
    long long power(long long a, long long n)
    {
        long long res = 1;
        while(n > 0)
        {
            if(n % 2)
            {
                res = (res * a) % mod;
                n--;
            }
            else
            {
                a = (a * a) % mod;
                n = n / 2;
            }
        }
        
        return res % mod;
    }
    
    int mod = 1e9 + 7;
    int f(long long ind, long long cnt, long long sum, vector<int> &nums, int k, vector<vector<vector<long long>>> &dp)
    {
        int n = nums.size();
        
        if(sum == k)
            return power(2ll, (long long)n - cnt);
        else if(sum > k)
            return 0;
        if(ind >= n)
            return 0;
        
        if(dp[ind][cnt][sum] != -1)
            return dp[ind][cnt][sum];
        
        long long take = f(ind + 1, cnt + 1, sum + nums[ind], nums, k, dp);
        long long notTake = f(ind + 1, cnt, sum, nums, k, dp);
        
        return dp[ind][cnt][sum] = (take + notTake) % mod;
    }
    
    int sumOfPower(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(k + 1, vector<long long>(k + 1, -1)));
        
        return f(0, 0, 0, nums, k, dp);
    }
};