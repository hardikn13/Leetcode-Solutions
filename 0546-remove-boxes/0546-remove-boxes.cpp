class Solution {
public:
    int f(int low, int high, int cnt, vector<int> &boxes, vector<vector<vector<int>>> &dp)
    {
        if(low > high)
            return 0;

        if(dp[low][high][cnt] != -1)
            return dp[low][high][cnt];

        int l = low, c = cnt;
        while(low < high && boxes[low] == boxes[low + 1])
        {
            cnt++;
            low++;
        }

        int ans = (cnt + 1) * (cnt + 1) + f(low + 1, high, 0, boxes, dp);

        for(int ind = low + 1; ind <= high; ind++)
        {
            if(boxes[l] == boxes[ind])
                ans = max(ans, f(ind, high, cnt + 1, boxes, dp) + f(low + 1, ind - 1, 0, boxes, dp));
        }

        return dp[l][high][c] = ans;
    }

    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n + 1, -1)));
        return f(0, n - 1, 0, boxes, dp);
    }
};