class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        while(right > left)
            right &= right - 1;
        
        return right;
    }
};





// ANOTHER APPROACH
// ----------------

// int rangeBitwiseAnd(int left, int right) {
        
//         bitset<32> b(left);
//         for(int i = 0; i < 32; i++)
//         {
//             if(b[i])
//             {
//                 bitset<32> pw(pow(2, i));
//                 long long x = b.to_ulong() + pow(2, i);
//                 bitset<32> ans(x);
                
//                 if(x <= right)
//                     b.reset(i);
//                 else
//                     return b.to_ulong();
//             }
//         }
        
//         return 0;
//     }