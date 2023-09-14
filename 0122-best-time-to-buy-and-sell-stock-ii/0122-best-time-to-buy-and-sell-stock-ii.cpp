class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size(), sum = 0;
        
        for(int i = 1; i < n; i++)
        {
            if(prices[i] - prices[i - 1] > 0)
            {
                sum += prices[i] - prices[i - 1];   
            }
        }
        
        return sum;
    }
};