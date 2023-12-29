class Solution {
public:
    int integerBreak(int n) {
        
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        
        for(int i = 0; i <= n; i++)
        {
            prev[i] = 1;
        }
        
        for(int ind = 2; ind < n; ind++)
        {
            for(int target = 0; target <= n; target++)
            {
                int notTake = prev[target];
                int take = 0;
                if(target >= ind)
                {
                    take = ind * curr[target - ind];
                }

                curr[target] = max(take, notTake);
            }
            prev = curr;
        }
        
        return prev[n];
    }
};