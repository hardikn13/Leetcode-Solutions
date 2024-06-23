class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> minDeque, maxDeque;
        int i = 0, j = 0, n = nums.size();
        int ans = 0;

        while(j < n)
        {
            while(!minDeque.empty() && minDeque.back() > nums[j])
                minDeque.pop_back();
                
            minDeque.push_back(nums[j]);

            while(!maxDeque.empty() && maxDeque.back() < nums[j])
                maxDeque.pop_back();

            maxDeque.push_back(nums[j]);

            while(!minDeque.empty() && !maxDeque.empty() && maxDeque.front() - minDeque.front() > limit)
            {
                if(minDeque.front() == nums[i])
                    minDeque.pop_front();
                    
                if(maxDeque.front() == nums[i])
                    maxDeque.pop_front();
                
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};
