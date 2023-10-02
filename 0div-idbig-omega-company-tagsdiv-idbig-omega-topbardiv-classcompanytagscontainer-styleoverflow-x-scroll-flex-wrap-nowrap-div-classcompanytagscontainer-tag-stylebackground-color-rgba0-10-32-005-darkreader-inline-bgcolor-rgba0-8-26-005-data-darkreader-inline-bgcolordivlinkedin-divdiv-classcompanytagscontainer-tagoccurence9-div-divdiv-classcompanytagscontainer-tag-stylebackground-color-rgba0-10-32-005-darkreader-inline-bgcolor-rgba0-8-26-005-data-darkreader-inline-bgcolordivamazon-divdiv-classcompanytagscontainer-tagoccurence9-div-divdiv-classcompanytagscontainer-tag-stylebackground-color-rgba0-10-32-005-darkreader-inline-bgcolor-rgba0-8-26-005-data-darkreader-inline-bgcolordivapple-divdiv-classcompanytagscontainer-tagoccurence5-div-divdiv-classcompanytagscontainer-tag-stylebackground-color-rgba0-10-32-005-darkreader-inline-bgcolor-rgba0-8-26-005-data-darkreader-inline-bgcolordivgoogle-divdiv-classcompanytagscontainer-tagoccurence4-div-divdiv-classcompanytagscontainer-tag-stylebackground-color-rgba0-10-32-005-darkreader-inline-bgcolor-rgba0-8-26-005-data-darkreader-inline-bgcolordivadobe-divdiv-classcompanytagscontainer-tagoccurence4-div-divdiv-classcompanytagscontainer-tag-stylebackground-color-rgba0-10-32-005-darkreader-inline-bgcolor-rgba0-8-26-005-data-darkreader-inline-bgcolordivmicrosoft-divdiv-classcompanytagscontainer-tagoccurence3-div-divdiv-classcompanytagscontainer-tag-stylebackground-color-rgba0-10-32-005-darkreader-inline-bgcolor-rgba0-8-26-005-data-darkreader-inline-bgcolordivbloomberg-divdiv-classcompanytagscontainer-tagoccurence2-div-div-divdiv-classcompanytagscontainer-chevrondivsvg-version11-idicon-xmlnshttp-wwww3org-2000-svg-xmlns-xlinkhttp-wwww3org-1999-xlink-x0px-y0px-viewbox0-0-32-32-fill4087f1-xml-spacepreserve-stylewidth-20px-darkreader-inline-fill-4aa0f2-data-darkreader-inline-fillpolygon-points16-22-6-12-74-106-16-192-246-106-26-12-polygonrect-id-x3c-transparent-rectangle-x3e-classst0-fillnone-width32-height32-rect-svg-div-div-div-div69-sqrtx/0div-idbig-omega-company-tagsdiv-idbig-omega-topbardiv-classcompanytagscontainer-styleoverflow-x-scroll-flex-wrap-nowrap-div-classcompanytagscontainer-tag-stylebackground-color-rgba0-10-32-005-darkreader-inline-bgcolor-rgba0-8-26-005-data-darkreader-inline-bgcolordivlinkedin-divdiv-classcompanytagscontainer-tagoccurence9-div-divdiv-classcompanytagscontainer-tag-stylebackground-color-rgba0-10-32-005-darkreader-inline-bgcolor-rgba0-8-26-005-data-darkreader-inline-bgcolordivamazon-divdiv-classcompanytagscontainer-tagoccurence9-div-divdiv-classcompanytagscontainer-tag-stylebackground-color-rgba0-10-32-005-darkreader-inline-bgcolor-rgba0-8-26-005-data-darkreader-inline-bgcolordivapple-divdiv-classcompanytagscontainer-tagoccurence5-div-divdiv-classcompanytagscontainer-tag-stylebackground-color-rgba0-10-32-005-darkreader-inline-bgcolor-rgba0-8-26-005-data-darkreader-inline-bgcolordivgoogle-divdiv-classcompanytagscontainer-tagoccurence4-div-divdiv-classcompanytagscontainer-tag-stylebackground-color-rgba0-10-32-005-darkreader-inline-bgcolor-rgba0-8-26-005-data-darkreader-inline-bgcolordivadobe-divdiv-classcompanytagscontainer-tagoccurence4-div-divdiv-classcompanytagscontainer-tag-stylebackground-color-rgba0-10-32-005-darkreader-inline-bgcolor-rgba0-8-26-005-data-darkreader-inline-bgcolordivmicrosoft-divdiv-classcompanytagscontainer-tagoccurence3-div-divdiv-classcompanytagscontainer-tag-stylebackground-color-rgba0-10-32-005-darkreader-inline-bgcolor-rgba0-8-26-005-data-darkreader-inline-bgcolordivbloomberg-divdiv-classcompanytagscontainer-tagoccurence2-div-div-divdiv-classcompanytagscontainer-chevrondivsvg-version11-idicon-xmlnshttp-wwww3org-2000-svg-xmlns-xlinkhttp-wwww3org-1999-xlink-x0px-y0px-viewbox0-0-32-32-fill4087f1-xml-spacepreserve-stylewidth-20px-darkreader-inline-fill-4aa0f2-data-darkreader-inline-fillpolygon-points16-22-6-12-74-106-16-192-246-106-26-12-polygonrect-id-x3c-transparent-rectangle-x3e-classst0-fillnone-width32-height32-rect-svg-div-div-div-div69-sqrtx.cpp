class Solution {
public:
    int mySqrt(int x) {
        
        if(x == 1 || x == 0)
            return x;
        
        int low = 0, high = x - 1;
        long long ans = INT_MIN;
        
        while(low <= high)
        {
            long long mid = (low + high) / 2;
            
            if(mid * mid > x)
                high = mid - 1;
            else
            {
                ans = max(ans, mid);
                low = mid + 1;
            }
        }
        
        return ans;
    }
};