class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans = 0;
        for(int k = 0; k < 32; k++)
        {
            int temp = (1 << k);
            
            int cntZeroes = 0, cntOnes = 0;
            for(auto it : nums)
            {
                if((it & temp) == 0)
                    cntZeroes++;
                else
                    cntOnes++;
            }
            
            if(cntOnes % 3 == 1)
                ans = (ans | temp);
        }
        
        return ans;
    }
};