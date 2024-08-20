class Solution {
public:
    bool f(int mid, int m, vector<int> &nums)
    {
        int n = nums.size();
        int place = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] >= place)
            {
                m--;
                place = mid + nums[i];
            }
        }

        if(m > 0)
            return false;
        return true;
    }

    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int low = 1, high = position[n - 1];
        int ans = 0;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            bool check = f(mid, m, position);

            if(check)
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        return ans;
    }
};