class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        
        int x = 0;
        for(int i = 0; i < nums.size(); i++)
            x ^= nums[i];
        
        return x;
    }
};