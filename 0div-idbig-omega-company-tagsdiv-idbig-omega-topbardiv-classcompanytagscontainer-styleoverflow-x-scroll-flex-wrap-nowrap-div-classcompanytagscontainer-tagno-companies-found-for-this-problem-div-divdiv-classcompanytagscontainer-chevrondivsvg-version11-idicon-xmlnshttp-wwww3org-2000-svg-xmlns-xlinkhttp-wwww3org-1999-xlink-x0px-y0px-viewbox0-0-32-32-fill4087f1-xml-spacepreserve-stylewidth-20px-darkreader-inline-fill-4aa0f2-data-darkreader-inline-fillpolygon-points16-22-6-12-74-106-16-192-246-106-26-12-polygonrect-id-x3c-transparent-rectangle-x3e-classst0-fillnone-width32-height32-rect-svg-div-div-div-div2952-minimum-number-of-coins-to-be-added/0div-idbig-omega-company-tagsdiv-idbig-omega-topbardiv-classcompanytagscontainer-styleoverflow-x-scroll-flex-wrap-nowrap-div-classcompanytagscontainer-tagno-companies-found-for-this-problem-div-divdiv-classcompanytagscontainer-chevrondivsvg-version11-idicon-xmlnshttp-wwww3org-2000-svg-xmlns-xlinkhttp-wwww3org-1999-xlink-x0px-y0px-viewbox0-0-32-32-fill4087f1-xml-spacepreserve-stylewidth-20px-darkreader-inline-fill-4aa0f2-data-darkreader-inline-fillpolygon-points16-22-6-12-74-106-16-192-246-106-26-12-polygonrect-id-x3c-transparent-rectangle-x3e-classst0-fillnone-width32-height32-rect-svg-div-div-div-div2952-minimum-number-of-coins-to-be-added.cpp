class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        
        sort(coins.begin(), coins.end());
        
        long long reach = 0, coinsNeed = 0;

        for (int coin : coins) 
        {
            if(coin <= reach + 1)
                reach += coin;
            else
            {
                while(coin > reach + 1)
                {
                    coinsNeed = coinsNeed + 1;
                    reach += reach + 1;
                }
                
                reach += coin;
            }
        }

        while(target > reach)
        {
            coinsNeed = coinsNeed + 1;
            reach += reach + 1;
        }

        return coinsNeed;
    }
};