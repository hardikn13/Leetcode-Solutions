class Solution {
public:
    
    int f(int mid, vector<int>& weights)
    {
        int n = weights.size();
        int total = 0, days = 0;
        
        for(int i = 0; i < n; i++)
        {
            total += weights[i];
            if(total > mid && mid >= weights[i])
            {
                days++;
                i = i - 1;
                total = 0;
            }
            else if(total == mid)
            {
                days++;
                total = 0;
            }
            else if(total <= mid && i == n - 1)
                days++;
            else if(total > mid && mid < weights[i])
                return INT_MAX;
        }
        
        return days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size(), sum = 0;
        
        for(int i = 0; i < n; i++)
            sum += weights[i];
        
        int low = *min_element(weights.begin(), weights.end());
        int high = sum;
        
        while(low <= high)
        {
            int mid = (low + high) / 2;
            
            if(f(mid, weights) > days)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return low;
    }
};