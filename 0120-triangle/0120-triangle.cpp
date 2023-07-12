class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n, 0), curr(n, 0);
        for(int j = 0; j < n; j++) front[j] = triangle[n-1][j];
        for(int i = n-2; i >= 0; i--)
        {
            for(int j = i; j >= 0; j--)
            {
                int d = triangle[i][j] + front[j];
                int dg = triangle[i][j] + front[j+1];
                curr[j] = min(d, dg);
            }
            front = curr;
        }
        return front[0];
    }
};



// Tabulation
// ----------
// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>> dp(n, vector<int> (n, 0));
//         for(int j = 0; j < n; j++) dp[n-1][j] = triangle[n-1][j];
//         for(int i = n-2; i >= 0; i--)
//         {
//             for(int j = i; j >= 0; j--)
//             {
//                 int d = triangle[i][j] + dp[i+1][j];
//                 int dg = triangle[i][j] + dp[i+1][j+1];
//                 dp[i][j] = min(d, dg);
//             }
//         }
//         return dp[0][0];
//     }
// };