class Solution {
public:
    int mod = 1e9 + 7;
    int maximumXorProduct(long long a, long long b, int n) {
        
        long long xXORa = 0, xXORb = 0;
        
        for(long long i = 49; i >= n; i--)
        {
            int a_ith_bit = (a >> i) & 1;
            int b_ith_bit = (b >> i) & 1;
            
            if(a_ith_bit == 1)
                xXORa ^= (1ll << i);
            if(b_ith_bit == 1)
                xXORb ^= (1ll << i);
        }
        
        for(int i = n - 1; i >= 0; i--)
        {
            int a_ith_bit = (a >> i) & 1;
            int b_ith_bit = (b >> i) & 1;
            
            if(a_ith_bit == b_ith_bit)
            {
                xXORa ^= (1ll << i);
                xXORb ^= (1ll << i);
            }
            else
            {
                if(xXORa < xXORb)
                    xXORa ^= (1ll << i);
                else
                    xXORb ^= (1ll << i);
            }
        }
        
        return ((xXORa % mod) * (xXORb% mod)) % mod;
    }
};