class Solution {
public:
    int f(vector<int>& nums, int goal) {
        if(goal < 0)
            return 0;

        int n = nums.size();
        int sum = 0, cnt = 0;
        int i = 0, j = 0;

        while(j < n)
        {
            sum += nums[j];
            if(sum <= goal)
                cnt += (j - i + 1);
            else
            {
                while(sum > goal)
                {
                    sum -= nums[i];
                    i++;
                }

                cnt += (j - i + 1);
            }

            j++;
        }

        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums, goal) - f(nums, goal - 1);
    }
};