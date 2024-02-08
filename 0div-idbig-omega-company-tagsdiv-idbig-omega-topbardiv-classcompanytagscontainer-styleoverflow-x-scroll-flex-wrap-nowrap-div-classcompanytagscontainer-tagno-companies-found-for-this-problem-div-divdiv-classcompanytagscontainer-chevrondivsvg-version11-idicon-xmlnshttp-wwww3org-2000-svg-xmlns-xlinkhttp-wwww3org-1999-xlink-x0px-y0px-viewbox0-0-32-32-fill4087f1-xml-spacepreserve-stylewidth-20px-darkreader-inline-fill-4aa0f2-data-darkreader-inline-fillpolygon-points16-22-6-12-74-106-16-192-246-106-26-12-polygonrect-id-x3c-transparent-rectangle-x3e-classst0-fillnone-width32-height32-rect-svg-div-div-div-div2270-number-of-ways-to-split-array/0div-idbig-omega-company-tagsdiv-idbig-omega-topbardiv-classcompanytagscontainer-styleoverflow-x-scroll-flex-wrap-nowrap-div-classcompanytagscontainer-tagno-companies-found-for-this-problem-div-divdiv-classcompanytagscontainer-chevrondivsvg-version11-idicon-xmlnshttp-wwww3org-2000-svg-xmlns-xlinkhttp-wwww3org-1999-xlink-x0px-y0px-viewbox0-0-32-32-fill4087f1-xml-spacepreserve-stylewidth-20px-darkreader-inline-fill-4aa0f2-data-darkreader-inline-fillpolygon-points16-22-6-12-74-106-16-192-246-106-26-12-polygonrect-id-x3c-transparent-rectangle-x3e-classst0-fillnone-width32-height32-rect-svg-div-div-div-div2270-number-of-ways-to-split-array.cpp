class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<long long> prefixSum(n, 0);
        vector<long long> suffixSum(n, 0);
        
        long long sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            prefixSum[i] = sum;
        }
        
        sum = nums[n - 1];
        for(int i = n - 2; i >= 0; i--)
        {
            suffixSum[i] = sum;
            sum += nums[i];
        }
        
        int ans = 0;
        for(int i = 0; i < n - 1; i++)
        {
            if(prefixSum[i] >= suffixSum[i])
                ans++;
        }
        
        return ans;
    }
};