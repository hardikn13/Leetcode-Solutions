class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ones = 0, twos = 0, threes = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            ones = (ones ^ nums[i]) & ~(twos);
            twos = (twos ^ nums[i]) & ~(ones);
            threes = (threes ^ nums[i]) & ~(twos);
        }
        
        return ones;
    }
};







// ANOTHER APPROACH
// ----------------

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
        
//         int ans = 0;
//         for(int k = 0; k < 32; k++)
//         {
//             int temp = (1 << k);
            
//             int cntZeroes = 0, cntOnes = 0;
//             for(auto it : nums)
//             {
//                 if((it & temp) == 0)
//                     cntZeroes++;
//                 else
//                     cntOnes++;
//             }
            
//             if(cntOnes % 3 == 1)
//                 ans = (ans | temp);
//         }
        
//         return ans;
//     }
// };