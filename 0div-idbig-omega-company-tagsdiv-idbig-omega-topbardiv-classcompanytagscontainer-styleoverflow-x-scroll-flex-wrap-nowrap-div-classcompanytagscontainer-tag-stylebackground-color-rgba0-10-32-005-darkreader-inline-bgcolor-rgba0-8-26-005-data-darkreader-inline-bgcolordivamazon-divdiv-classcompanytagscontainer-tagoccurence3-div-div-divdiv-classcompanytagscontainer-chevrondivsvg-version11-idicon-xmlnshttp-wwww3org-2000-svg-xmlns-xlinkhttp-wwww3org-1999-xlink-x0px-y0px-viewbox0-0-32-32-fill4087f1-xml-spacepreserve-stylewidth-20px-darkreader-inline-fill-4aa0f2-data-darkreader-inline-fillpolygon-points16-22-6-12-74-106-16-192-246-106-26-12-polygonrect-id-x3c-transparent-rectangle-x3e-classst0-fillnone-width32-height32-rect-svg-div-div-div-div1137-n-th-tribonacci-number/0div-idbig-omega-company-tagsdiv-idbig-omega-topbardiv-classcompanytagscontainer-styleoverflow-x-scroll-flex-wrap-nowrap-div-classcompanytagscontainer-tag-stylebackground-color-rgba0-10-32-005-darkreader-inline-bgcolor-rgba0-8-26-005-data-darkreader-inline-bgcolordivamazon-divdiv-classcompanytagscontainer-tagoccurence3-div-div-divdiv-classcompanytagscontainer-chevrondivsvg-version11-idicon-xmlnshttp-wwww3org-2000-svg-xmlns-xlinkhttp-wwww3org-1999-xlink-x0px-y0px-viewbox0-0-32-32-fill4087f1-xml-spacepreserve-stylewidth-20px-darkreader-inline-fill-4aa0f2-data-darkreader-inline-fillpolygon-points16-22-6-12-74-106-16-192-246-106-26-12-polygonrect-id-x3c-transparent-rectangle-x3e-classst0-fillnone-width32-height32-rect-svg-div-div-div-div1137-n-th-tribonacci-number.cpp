class Solution {
public:
    int tribonacci(int n) {
        
        if(n == 0)
            return 0;
        if(n == 1 || n == 2)
            return 1;
        
        int z1 = 0, z2 = 1, z3 = 1, z, cnt = 2;
        while(cnt != n)
        {
            z = z1 + z2 + z3;
            
            z1 = z2;
            z2 = z3;
            z3 = z;
            cnt++;
        }
        
        return z;
    }
};