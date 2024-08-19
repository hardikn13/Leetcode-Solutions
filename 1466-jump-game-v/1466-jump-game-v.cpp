class Solution {
public:
    int f(int ind, int d, vector<int> &arr, vector<int> &dp)
    {
        int n = arr.size();

        if(dp[ind] != -1)
            return dp[ind];

        int cnt = 0;
        for(int i = 1; i <= d && ind + i < n; i++)
        {
            if(arr[ind + i] >= arr[ind])
                break;
            
            cnt = max(cnt, 1 + f(ind + i, d, arr, dp));
        }

        for(int i = 1; i <= d && ind - i >= 0; i++)
        {
            if(arr[ind - i] >= arr[ind])
                break;
            
            cnt = max(cnt, 1 + f(ind - i, d, arr, dp));
        }
        
        return dp[ind] = cnt;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int ans = 0;

        for(int i = 0; i < n; i++)
            ans = max(ans, 1 + f(i, d, arr, dp));

        return ans;
    }
};