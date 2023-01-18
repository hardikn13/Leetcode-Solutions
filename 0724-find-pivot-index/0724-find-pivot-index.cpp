class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int prefix_sum  =0;
        for(int i= 0; i < nums.size(); i++){
            prefix_sum += nums[i];
        }
        int left_sum =0; 
        int right_sum = prefix_sum ;
        for(int i= 0; i < nums.size(); i++){
            right_sum = right_sum - nums[i];
            if(left_sum == right_sum)
                return i;
            
            left_sum += nums[i];
        }
        return -1;
    }
};

// Same Approach
// -------------

// int pivotIndex(vector<int>& nums) {
//         int sumR = accumulate(nums.begin(), nums.end(), 0);
//         int sumL = 0;
//         for (int i = 0; i < nums.size(); i++) {
//              sumR -= nums[i];
//              if (sumL == sumR)
//                  return i;
//              sumL += nums[i];
//          }
//          return -1;
//      }
//  };




// Time Limit Exceeded
// -------------------

// int pivotIndex(vector<int>& nums) {
//         int suml=0,sumr=0,j=0,k=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             suml=0;
//             sumr=0;
//             j=i+1;
//             k=i-1;
//             while(j<nums.size())
//             {
//                 if(i==nums.size()-1)
//                 {
//                     sumr=0;
//                     break;
//                 }
//                 sumr+=nums[j];
//                 j++;
//             }
//             while(k>=0)
//             {
//                 if(i==0)
//                 {
//                     suml=0;
//                     break;
//                 }
//                 suml+=nums[k];
//                 k--;
//             }
//             if(suml==sumr)
//             {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };