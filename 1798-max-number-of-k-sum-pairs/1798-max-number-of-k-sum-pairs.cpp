class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = n - 1, ans = 0;
        while(i < j)
        {
            if(nums[i] + nums[j] < k)
                i++;
            else if(nums[i] + nums[j] > k)
                j--;
            else
            {
                i++;
                j--;
                ans++;
            }
        }

        return ans;
    }
};