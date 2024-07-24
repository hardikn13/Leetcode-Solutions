class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int n = nums.size();
        int sum = 0;
        double ans = INT_MIN;
        int i = 0, j = 0;

        while(j < n)
        {
            if(j - i + 1 < k)
            {
                sum += nums[j];
                j++;
            }
            else if(j - i + 1 == k)
            {
                sum += nums[j];
                ans = max(ans, (double)sum);
                j++;
            }
            else
            {
                sum += nums[j];
                sum -= nums[i];
                ans = max(ans, (double)sum);
                i++;
                j++;
            }
        }

        return ans / k;
    }
};