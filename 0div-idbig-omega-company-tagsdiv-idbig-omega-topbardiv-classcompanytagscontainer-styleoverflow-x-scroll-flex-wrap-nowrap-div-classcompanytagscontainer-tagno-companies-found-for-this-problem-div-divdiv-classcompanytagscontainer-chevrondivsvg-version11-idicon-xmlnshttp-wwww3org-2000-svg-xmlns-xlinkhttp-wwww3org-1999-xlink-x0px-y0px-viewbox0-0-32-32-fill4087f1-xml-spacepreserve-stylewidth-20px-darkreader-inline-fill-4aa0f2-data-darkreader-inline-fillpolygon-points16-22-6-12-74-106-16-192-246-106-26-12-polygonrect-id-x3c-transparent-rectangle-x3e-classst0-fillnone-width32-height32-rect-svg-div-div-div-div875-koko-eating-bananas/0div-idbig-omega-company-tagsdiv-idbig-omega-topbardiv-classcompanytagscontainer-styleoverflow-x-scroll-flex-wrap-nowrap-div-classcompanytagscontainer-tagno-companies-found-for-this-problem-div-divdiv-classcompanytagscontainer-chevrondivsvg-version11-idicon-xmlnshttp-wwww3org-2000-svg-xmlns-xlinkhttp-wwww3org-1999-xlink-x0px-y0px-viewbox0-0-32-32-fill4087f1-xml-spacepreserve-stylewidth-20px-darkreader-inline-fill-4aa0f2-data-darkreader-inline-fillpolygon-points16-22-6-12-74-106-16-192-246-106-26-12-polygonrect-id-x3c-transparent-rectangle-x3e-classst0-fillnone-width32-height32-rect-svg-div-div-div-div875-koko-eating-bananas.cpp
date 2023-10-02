class Solution {
public:
    
    long long f(int hourly, vector<int> &piles)
    {
        long long totalHours = 0, n = piles.size();
        for(int i = 0; i < n; i++)
            totalHours += ceil((double)piles[i] / (double)hourly);
        
        return totalHours;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();
        int low = 1, high = *max_element(piles.begin(), piles.end());
        
        while(low <= high)
        {
            int mid = (low + high) / 2;
            
            if(f(mid, piles) > h)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return low;
    }
};