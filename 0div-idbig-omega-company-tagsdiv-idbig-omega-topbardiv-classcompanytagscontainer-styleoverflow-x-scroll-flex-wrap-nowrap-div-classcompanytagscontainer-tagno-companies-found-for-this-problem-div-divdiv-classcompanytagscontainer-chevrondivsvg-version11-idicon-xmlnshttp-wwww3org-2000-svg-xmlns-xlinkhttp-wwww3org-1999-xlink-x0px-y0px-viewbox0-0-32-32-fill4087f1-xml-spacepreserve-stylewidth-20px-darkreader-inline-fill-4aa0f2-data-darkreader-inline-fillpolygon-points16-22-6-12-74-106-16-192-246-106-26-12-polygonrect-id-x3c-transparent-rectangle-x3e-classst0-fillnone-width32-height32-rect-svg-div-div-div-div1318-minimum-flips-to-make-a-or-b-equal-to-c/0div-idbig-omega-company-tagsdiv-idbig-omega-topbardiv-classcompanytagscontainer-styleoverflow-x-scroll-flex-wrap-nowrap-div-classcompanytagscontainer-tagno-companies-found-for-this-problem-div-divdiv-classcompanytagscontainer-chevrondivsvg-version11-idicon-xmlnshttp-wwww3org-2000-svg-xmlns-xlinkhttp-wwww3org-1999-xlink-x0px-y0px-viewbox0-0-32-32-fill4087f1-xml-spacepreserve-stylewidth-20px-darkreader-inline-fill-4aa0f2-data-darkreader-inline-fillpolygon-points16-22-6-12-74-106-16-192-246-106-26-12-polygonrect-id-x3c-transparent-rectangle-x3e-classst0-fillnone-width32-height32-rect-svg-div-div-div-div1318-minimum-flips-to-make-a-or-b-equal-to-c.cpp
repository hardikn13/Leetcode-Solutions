class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        bitset<32> p1(a);
        bitset<32> p2(b);
        bitset<32> p3(c);
        
        int cnt = 0;
        for(int i = 0; i < 32; i++)
        {
            if((p1[i] | p2[i]) != p3[i])
            {
                if(p1[i] == 1 && p2[i] == 1)
                    cnt += 2;
                else
                    cnt += 1;
            }
        }
        
        return cnt;
    }
};