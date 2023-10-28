#include <iostream>
#include <vector>

class Solution {
private:
    static const int mod = 1000000007;

public:
    int countVowelPermutation(int n) {
        std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(6, -1));
        long long ans = recursion(n, 5, dp);
        return static_cast<int>(ans % mod);
    }

    long long recursion(int n, int last, std::vector<std::vector<long long>>& dp) {
        if (n == 0)
            return 1LL;

        if (dp[n][last] != -1)
            return dp[n][last];

        long long ans = 0LL;

        if (last == 0)
            ans = recursion(n - 1, 1, dp);
        if (last == 1)
            ans = (recursion(n - 1, 0, dp) + recursion(n - 1, 2, dp)) % mod;
        if (last == 2)
            ans = (recursion(n - 1, 0, dp) + recursion(n - 1, 1, dp) + recursion(n - 1, 3, dp) + recursion(n - 1, 4, dp)) % mod;
        if (last == 3)
            ans = (recursion(n - 1, 2, dp) + recursion(n - 1, 4, dp)) % mod;
        if (last == 4)
            ans = recursion(n - 1, 0, dp);
        if (last == 5)
            ans = (recursion(n - 1, 0, dp) + recursion(n - 1, 1, dp) + recursion(n - 1, 2, dp) + recursion(n - 1, 3, dp) + recursion(n - 1, 4, dp)) % mod;

        return dp[n][last] = ans;
    }
};
