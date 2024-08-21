class Solution {
public:
    double f(int i, int j, int poured, vector<vector<double>> &dp)
    {
        if(i < 0 || j < 0 || i < j)
            return 0.0;

        if(i == 0 && j == 0)
            return poured;

        if(dp[i][j] != -1)
            return dp[i][j];

        double leftUp = (f(i - 1, j - 1, poured, dp) - 1) / 2.0;
        double rightUp = (f(i - 1, j, poured, dp) - 1) / 2.0;

        if(leftUp < 0)
            leftUp = 0.0;
        if(rightUp < 0)
            rightUp = 0.0;

        return dp[i][j] = leftUp + rightUp;
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 1, vector<double>(query_glass + 1, -1));
        return min(1.0, f(query_row, query_glass, poured, dp));
    }
};