class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
                int n = nums.size();
                vector<int> dp(n, 1), hash(n);
                int maxi = 1, lastIndex = 0;
                sort(nums.begin(), nums.end());

                for(int ind = 0; ind < n; ind++)
                {
                    hash[ind] = ind;
                    for(int prev = 0; prev < ind; prev++)
                    {
                        if(nums[ind] % nums[prev] == 0 && 1 + dp[prev] > dp[ind])
                        {
                            dp[ind] = 1 + dp[prev];
                            hash[ind] = prev;
                        }
                    }
                    if(dp[ind] > maxi)
                    {
                        maxi = dp[ind];
                        lastIndex = ind;
                    }
                }

                vector<int> temp;
                temp.push_back(nums[lastIndex]);

                while(hash[lastIndex] != lastIndex)
                {
                    lastIndex = hash[lastIndex];
                    temp.push_back(nums[lastIndex]);
                }

                reverse(temp.begin(), temp.end());
                return temp;
    }
};