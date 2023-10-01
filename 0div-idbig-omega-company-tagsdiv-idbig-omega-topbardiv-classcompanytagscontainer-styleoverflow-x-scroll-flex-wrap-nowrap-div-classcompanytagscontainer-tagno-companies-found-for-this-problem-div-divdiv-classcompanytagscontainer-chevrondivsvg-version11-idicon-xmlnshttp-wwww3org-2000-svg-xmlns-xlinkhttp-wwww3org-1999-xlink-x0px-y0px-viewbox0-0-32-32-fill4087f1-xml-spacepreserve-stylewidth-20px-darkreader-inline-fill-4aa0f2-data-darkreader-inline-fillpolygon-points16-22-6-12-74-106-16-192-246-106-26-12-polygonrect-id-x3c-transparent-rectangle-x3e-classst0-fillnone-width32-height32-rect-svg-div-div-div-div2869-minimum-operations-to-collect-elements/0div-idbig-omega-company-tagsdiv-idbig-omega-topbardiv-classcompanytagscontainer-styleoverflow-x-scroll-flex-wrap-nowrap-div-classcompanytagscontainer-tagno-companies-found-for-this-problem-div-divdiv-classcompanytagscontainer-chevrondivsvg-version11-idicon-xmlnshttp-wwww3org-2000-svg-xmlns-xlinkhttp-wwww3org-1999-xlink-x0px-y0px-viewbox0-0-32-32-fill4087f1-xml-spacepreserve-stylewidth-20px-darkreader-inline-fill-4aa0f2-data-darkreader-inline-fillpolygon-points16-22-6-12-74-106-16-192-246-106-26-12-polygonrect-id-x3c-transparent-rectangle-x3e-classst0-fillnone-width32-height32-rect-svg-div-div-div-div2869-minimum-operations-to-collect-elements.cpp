class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        map<int, int> ans;
        int cnt = 0;
        
        for(int i = n - 1; i >= 0; i--)
        {
            cnt++;
            if(nums[i] <= k && nums[i] != 0)
            {
                ans[nums[i]]++;
                if(ans.size() == k)
                    return cnt;
            }
        }
        return -1;
    }
};