class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size(), mini = prices[0], profit = 0;
        
        for(int i = 0; i < n; i++)
        {
            int cost = prices[i] - mini;
            profit = max(profit, cost);
            if(prices[i] < mini)
                mini = prices[i];
        }
        
        return profit;
    }
};