class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int row = points.size();
        if(row == 0)
            return 0;

        int col = points[0].size();
        vector<long long> dp(points[0].begin(), points[0].end());
        vector<long long> left(col);
        vector<long long> right(col);

        for(int i = 1; i < row; i++)
        {
            left.front() = dp.front();
            for(int j = 1; j < col; j++)
                left[j] = max(dp[j], left[j - 1] - 1);

            right.back() = dp.back();
            for(int j = col - 2; j >= 0; j--)
                right[j] =  max(dp[j], right[j + 1] - 1);

            for(int j = 0; j < col; j++)
                dp[j] = points[i][j] + max(left[j], right[j]);
        }

        return *max_element(dp.begin(), dp.end());
    }
};