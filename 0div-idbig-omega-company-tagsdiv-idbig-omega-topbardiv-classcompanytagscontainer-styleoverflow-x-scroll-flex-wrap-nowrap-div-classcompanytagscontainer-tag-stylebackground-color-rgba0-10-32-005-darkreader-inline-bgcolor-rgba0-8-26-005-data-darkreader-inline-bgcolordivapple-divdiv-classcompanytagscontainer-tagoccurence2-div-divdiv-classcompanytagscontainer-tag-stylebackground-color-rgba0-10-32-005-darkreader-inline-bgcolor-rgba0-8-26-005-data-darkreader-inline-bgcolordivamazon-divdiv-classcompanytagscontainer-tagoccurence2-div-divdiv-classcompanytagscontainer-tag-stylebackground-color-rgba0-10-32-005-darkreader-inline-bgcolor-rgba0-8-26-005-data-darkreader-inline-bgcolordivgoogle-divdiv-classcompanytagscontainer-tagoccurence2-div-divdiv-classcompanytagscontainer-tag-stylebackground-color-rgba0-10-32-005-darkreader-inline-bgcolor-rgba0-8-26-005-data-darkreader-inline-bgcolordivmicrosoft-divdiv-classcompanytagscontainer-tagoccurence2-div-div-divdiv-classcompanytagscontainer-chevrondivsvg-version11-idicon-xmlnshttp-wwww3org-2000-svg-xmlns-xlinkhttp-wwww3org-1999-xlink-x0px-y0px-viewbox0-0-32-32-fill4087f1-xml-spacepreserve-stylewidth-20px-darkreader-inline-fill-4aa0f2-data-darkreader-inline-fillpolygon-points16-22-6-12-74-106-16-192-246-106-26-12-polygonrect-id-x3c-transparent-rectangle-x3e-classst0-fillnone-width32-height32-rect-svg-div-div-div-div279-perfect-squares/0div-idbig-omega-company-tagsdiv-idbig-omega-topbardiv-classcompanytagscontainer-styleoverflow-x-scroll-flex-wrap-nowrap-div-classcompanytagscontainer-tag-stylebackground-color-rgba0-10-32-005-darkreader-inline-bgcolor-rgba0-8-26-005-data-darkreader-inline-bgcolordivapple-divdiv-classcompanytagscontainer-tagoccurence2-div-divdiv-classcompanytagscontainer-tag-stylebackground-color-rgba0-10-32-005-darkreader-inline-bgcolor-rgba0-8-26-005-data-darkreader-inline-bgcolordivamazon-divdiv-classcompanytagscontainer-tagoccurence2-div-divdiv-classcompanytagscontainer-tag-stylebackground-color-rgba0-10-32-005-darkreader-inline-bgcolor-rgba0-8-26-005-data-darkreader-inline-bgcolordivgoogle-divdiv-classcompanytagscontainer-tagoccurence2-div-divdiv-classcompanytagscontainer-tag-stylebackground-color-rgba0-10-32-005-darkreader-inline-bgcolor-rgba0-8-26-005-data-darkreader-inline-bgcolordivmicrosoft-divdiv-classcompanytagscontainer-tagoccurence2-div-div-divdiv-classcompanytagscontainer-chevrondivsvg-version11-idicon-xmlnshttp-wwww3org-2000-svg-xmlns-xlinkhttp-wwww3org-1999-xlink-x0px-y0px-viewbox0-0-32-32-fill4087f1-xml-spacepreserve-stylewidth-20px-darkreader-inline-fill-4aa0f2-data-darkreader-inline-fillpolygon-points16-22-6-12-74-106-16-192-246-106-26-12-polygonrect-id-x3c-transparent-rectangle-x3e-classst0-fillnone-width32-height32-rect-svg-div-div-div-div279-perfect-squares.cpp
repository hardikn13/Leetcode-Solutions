#include <vector>
#include <cmath>

class Solution {
public:
    int numSquares(int n) {
        // Precompute perfect squares up to n
        std::vector<int> squares;
        for (int i = 1; i * i <= n; i++) {
            squares.push_back(i * i);
        }

        // Initialize dp array
        std::vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        // Dynamic programming to find the minimum number of perfect squares
        for (int i = 1; i <= n; i++) {
            for (int square : squares) {
                if (i - square >= 0) {
                    dp[i] = std::min(dp[i], 1 + dp[i - square]);
                }
            }
        }

        return dp[n];
    }
};
