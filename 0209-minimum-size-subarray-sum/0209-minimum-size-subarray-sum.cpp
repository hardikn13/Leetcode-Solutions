class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0, ans = INT_MAX;
        int i = 0, j = 0;
        while(j < n)
        {
            sum += nums[j];

            if(sum < target)
                j++;
            else
            {
                ans = min(ans, j - i + 1);
                while(sum >= target)
                {
                    sum -= nums[i];
                    i++;

                    if(sum >= target)
                        ans = min(ans, j - i + 1);
                }

                j++;
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};