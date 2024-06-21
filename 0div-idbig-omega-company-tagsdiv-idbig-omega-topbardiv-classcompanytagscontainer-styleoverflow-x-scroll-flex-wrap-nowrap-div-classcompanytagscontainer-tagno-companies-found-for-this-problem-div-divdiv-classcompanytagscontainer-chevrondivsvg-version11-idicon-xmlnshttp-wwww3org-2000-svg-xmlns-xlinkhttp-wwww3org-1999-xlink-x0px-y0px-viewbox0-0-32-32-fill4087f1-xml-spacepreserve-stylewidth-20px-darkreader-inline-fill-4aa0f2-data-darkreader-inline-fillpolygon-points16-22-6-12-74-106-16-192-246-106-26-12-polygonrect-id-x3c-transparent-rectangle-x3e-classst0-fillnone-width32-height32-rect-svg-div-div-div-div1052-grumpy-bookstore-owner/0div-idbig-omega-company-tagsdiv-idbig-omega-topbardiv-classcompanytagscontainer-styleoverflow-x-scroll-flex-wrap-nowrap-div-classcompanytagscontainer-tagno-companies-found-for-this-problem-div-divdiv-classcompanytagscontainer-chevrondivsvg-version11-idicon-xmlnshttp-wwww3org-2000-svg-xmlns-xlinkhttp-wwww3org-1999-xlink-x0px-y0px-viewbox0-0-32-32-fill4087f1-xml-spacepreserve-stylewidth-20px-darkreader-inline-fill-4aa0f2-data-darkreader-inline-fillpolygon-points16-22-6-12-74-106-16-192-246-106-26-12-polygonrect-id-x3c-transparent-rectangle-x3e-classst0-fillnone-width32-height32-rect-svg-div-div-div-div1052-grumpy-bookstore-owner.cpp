class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int ans = 0;
        for(int i = 0; i < customers.size(); i++)
        {
            if(grumpy[i] == 0)
            {
                ans += customers[i];
                customers[i] = 0;
            }
        }
        
        int i = 0;
        int j = 0;
        int sum = 0, maxi = 0;
        while(j < customers.size())
        {
            sum += customers[j];
            
           if(j - i + 1 <= minutes)
           {
               maxi = max(maxi, sum);
               j++;
           }
            else
            {
                sum -= customers[i];
                i++;
                maxi = max(maxi, sum);
                j++;
            }
        }
        
        return ans + maxi;
    }
};