class Solution {
public:
    int f(int n, int curr, int clipboard, vector<vector<int>> &dp)
    {
        if(curr == n)
            return 0;

        if(curr > n || clipboard > n)
            return 1'000'000;
        
        if(dp[curr][clipboard] != -1)
            return dp[curr][clipboard];

        int copy = 2 + f(n, curr + curr, curr, dp);
        int paste = 1 + f(n, curr + clipboard, clipboard, dp);

        return dp[curr][clipboard] = min(copy, paste);
    }

    int minSteps(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return n == 1 ? 0 : 1 + f(n, 1, 1, dp);
    }
};






// SIMPLE PASS
// -----------

//     int minSteps(int n) {
        
//         int operations = 0;
//         for(int i = 2; i <= n; i++)
//         {
//             while(n % i == 0)
//             {
//                 operations += i;
//                 n /= i;
//             }
//         }

//         return operations;
//     }