class Solution {
public:
    int check(int dist, vector<int> &nums)
    {
        int n = nums.size();
        int i = 0, j = 1;
        int cnt = 0;

        while(j < n)
        {
            if(nums[j] - nums[i] <= dist)
                cnt += j - i;
            else
            {
                while(i <= j && nums[j] - nums[i] > dist)
                    i++;
                
                cnt += j - i;
            }

            j++;
        }

        return cnt;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums[nums.size() - 1] - nums[0];
        int ans = 0;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            int z = check(mid, nums);

            if(z < k)
                low = mid + 1;
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};