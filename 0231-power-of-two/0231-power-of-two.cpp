class Solution {
public:
    bool isPowerOfTwo(int n) {
        float a;
        long long int b;
        if((n%2!=0&&n!=1)||(n==0)||(n<0))
        {
            return false;
        }
        a=log(n)/log(2);
        b=log(n)/log(2);
        if(a==b)
        {
            return true;
        }
        return false;
    }
};