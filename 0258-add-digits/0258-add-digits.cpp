class Solution {
public:
    int addDigits(int num) {
        int dsum=0;
            while(num)
            {
                dsum+=num%10;
                num=num/10;
                if(dsum>9&&num==0)
                {
                    num=dsum;
                    dsum=0;
                }
            }
        return dsum;
    }
};