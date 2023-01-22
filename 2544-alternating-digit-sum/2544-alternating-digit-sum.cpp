class Solution {
public:
    int alternateDigitSum(int n) {
        int sum=0;
        int count=0;
        int z=n;
        while(z)
        {
            count+=1;
            z/=10;
        }
        while(n)
        {
            if(count%2==0)
            {
                sum-=n%10;
                n/=10;
            }
            else
            {
                sum+=n%10;
                n/=10;
            }
            count--;
        }
        return sum;
    }
};