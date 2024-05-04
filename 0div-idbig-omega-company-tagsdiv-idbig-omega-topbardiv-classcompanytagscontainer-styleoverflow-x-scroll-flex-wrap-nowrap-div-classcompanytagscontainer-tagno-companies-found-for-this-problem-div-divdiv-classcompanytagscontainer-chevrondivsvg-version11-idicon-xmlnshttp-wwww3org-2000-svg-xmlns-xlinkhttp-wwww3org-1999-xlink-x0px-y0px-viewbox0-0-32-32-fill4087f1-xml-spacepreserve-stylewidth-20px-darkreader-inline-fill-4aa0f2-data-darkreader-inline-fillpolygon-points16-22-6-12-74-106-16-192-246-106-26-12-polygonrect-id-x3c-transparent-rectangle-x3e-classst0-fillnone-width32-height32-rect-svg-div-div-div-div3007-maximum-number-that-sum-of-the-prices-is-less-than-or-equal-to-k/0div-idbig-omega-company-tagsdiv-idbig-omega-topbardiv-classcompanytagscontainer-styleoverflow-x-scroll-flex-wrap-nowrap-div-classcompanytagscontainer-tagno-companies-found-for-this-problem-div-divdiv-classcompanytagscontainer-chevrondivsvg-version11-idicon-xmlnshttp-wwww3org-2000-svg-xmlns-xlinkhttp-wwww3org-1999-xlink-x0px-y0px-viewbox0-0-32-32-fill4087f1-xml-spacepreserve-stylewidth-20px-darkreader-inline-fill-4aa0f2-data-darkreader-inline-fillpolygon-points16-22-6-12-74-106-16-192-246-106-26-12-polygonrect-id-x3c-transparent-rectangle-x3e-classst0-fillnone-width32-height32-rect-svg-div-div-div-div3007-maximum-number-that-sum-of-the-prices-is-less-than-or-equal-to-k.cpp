class Solution {
public:
    typedef long long ll;
    vector<ll> bitCount;
    
    void getBitsCount(ll num)
    {
        if(num == 0)
            return;
        
        if(num == 1)
        {
            bitCount[0] += 1;
            return;
        }
        
        if(num == 2)
        {
            bitCount[0] += 1;
            bitCount[1] += 1;
            return;
        }
        
        ll bitLength = log2(num);
        ll nearPower2 = (1ll << bitLength);
        bitCount[bitLength] += (num - nearPower2 + 1);
        
        for(ll i = 0; i < bitLength; i++)
        {
            bitCount[i] += nearPower2 / 2;
        }
        
        num = num - nearPower2;
        getBitsCount(num);
    }
    
    long long findMaximumNumber(long long k, int x) {
        
        ll left = 0;
        ll right = 1e15;
        ll ans = 0;
        
        while(left <= right)
        {
            ll mid = left + (right - left) / 2;
            
            bitCount = vector<ll>(65, 0);
            getBitsCount(mid);
            
            ll totalPrice = 0;
            for(ll i = 0; i < log2(mid) + 1; i++)
            {
                if((i + 1) % x == 0)
                    totalPrice += bitCount[i];
            }
            
            if(totalPrice <= k)
            {
                ans = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        
        return ans;
    }
};