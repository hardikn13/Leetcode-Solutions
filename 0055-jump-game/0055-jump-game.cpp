class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), farthest = 0;
        for(int i = 0; i < n; i++)
        {
            if(farthest < i)
                return false;
                
            farthest = max(i + nums[i], farthest);
        }
        
        return true;
    }
};