class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        
        int s = nums.size();
        long long reach = 0;
        int ans = 0;
        int i = 0;
        
        while(reach < n)
        {
            if(i < s && nums[i] <= reach + 1)
            {
                reach += nums[i];
                i++;
            }
            else
            {
                reach += reach + 1;
                ans++;
            }
        }
        
        return ans;
    }
};