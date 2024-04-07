class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long cnt = 0;
        if(n % 2 != 0)
        {
            int dist = nums[n / 2] - k;
            if(dist == 0)
                return 0;
            else if(dist < 0)
            {
                for(int i = n / 2; i < n; i++)
                {
                    if(nums[i] < k)
                    {
                        cnt += abs(nums[i] - k);   
                    }
                }
            }
            else
            {
                for(int i = 0; i <= n / 2; i++)
                {
                    if(nums[i] > k)
                    {
                        cnt += abs(nums[i] - k);   
                    }
                }
            }
        }
        else
        {
            int dist = nums[n / 2] - k;
            if(dist == 0)
                return 0;
            else if(dist < 0)
            {
                for(int i = n / 2; i < n; i++)
                {
                    if(nums[i] < k)
                    {
                        cnt += abs(nums[i] - k);   
                    }
                }
            }
            else
            {
                for(int i = 0; i <= n / 2; i++)
                {
                    if(nums[i] > k)
                    {
                        cnt += abs(nums[i] - k);   
                    }
                }
            }
        }
        
        return cnt;
    }
};