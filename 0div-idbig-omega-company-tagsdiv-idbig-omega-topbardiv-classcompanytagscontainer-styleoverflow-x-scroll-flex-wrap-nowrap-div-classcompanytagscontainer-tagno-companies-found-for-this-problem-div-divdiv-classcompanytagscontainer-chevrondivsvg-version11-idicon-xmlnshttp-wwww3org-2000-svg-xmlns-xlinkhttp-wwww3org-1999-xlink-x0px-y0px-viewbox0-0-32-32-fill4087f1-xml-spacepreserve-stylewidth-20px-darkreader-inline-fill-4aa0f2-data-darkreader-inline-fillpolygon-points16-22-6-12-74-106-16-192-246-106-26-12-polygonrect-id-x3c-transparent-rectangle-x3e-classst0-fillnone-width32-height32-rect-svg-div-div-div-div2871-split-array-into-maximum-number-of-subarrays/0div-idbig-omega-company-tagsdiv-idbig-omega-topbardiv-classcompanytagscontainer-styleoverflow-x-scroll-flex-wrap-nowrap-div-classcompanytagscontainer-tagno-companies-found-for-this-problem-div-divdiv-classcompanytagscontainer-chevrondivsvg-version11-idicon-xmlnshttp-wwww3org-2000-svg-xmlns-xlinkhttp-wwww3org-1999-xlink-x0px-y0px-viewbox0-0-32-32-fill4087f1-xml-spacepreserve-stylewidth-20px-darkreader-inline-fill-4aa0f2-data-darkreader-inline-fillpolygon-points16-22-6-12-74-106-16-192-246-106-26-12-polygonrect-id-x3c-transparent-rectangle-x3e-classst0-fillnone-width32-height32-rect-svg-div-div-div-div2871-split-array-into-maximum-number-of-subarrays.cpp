class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        
        
        int mini = INT_MAX;
        for(auto var : nums){
            mini &= var;
        }
        if(mini != 0){
            return 1;
        }
        
        int small = INT_MAX, cnt = 0;
        for(auto var : nums){
            small &= var;
            if(small == mini){
                cnt++;
                small = INT_MAX;
            }
        } 
        return cnt;
            
    }
};