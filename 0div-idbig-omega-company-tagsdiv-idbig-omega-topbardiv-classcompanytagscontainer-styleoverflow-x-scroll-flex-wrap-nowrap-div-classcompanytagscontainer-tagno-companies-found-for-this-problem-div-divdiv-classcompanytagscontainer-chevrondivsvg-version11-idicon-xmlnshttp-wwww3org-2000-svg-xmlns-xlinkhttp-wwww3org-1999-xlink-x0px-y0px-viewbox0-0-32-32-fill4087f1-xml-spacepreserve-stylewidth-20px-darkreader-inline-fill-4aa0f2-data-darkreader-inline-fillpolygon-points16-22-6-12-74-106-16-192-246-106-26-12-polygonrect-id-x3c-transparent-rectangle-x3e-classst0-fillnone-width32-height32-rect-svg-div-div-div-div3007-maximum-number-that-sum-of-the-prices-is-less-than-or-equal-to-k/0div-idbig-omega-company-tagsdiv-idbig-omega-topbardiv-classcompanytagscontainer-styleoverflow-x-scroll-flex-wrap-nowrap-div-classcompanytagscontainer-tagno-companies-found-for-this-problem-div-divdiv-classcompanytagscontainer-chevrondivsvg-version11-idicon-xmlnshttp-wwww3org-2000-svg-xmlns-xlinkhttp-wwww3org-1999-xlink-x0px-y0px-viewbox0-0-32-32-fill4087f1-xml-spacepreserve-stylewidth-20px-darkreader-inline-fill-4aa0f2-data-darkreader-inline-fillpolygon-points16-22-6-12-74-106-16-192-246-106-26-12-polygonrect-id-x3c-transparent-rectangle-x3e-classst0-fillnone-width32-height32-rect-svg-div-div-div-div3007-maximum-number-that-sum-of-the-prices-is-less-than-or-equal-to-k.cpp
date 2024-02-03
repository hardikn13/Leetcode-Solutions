class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        
        long long l = 0, h = 1e18;
        long long ans = 0;
        
        while(l <= h)
        {
            long long mid = (l + h) / 2;
            long long ctr = 0;
            
            for(long long j = 0; j <= 60; j++)
            {
                if((j + 1) % x == 0)
                {
                    long long one = 1;
                    long long nn = (one << (j + 1));
                    long long pack = (mid + 1) / nn;
                    ctr += (pack * (nn / 2));
                    
                    if(ctr >= 1e15)
                        break;
                    
                    ctr += max((long long)0, ((mid + 1) % nn) - nn / 2);
                    
                    if(ctr >= 1e15)
                        break;
                }
            }
            
            if(ctr <= k)
            {
                l = mid + 1;
                ans = max(ans, mid);
            }
            else
            {
                h = mid - 1;
            }
        }
        
        return ans;
    }
};