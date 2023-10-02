class Solution {
public:
    
    int f(int mid, int k, vector<int>& bloomDay)
    {
        int n = bloomDay.size();
        int cnt = 0, bouquets = 0;
        for(int i = 0; i < n; i++)
        {
            if(bloomDay[i] <= mid)
                cnt++;
            else
            {
                bouquets += cnt / k;
                cnt = 0;
            }
        }
        
        bouquets += cnt / k;
        
        return bouquets;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        long long n = bloomDay.size();
        
        if((long long)m * (long long)k > n)
            return -1;
        
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        
        while(low <= high)
        {
            int mid = (low + high) / 2;
            
            if(f(mid, k, bloomDay) < m)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return low;
    }
};