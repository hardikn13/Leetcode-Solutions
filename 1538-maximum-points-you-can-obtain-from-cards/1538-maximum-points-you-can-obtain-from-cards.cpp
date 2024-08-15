class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int i = 0, j = 0;
        int len = n - k;
        long long total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        long long mini = INT_MAX;

        if(len == 0)
            return total;

        long long sum = 0;
        while(j < n)
        {
            sum += cardPoints[j];
            
            if(j - i + 1 == len)
            {
                mini = min(mini, sum);
                sum -= cardPoints[i];
                i++;
            }

            j++;
        }

        return total - mini;
    }
};