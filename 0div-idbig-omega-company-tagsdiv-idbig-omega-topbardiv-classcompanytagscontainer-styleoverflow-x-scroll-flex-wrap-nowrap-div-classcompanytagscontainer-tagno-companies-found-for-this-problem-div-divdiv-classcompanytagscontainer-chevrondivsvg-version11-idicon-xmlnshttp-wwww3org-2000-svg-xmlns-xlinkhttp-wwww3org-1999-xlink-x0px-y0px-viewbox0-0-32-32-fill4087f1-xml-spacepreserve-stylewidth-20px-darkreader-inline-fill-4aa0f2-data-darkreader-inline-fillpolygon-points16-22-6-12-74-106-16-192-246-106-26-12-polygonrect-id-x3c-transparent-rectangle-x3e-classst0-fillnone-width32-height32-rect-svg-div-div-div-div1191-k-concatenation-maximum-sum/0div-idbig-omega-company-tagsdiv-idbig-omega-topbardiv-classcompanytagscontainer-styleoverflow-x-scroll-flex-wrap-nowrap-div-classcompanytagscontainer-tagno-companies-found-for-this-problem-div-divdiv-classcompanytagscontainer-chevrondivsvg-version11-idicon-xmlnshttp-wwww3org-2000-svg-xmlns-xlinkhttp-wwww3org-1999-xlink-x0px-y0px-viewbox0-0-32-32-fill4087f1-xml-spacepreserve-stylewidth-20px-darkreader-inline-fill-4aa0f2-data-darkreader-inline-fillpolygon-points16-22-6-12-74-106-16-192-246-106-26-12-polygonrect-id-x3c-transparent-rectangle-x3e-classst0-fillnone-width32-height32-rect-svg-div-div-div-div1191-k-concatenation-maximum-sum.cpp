class Solution {
public:
    
    int mod = 1e9 + 7;
    long long kadane(vector<int> &v)
    {
        int sum = 0, maxi = 0;
        for(int i = 0; i < v.size(); i++)
        {
            sum += v[i];
            
            if(sum < 0)
                sum = 0;
            
            maxi = max(maxi, sum);
        }
        
        return maxi;
    }
    
    int positiveSum(long long sum, int k, vector<int> &arr)
    {
        pair<long long, long long> maxes = getMaxes(arr, sum);
        long long maxSum = kadane(arr);
        
        if(k == 1)
            return maxSum % mod;
        
        long long ans = (1ll * (k - 2) * sum) % mod;
        ans = (ans + maxes.first + maxes.second) % mod;
        return ans;
    }
    
    pair<long long, long long> getMaxes(vector<int> &arr, long long sum)
    {
        long long maxPrefSum = 0;
        long long maxSuffSum = sum;
        long long currPrefSum = 0;
        long long currSuffSum = sum;
        
        for(int i = 0; i < arr.size(); i++)
        {
            currPrefSum += arr[i];
            currSuffSum -= arr[i];
            
            maxPrefSum = max(maxPrefSum, currPrefSum);
            maxSuffSum = max(maxSuffSum, currSuffSum);
        }
        
        return {maxPrefSum, maxSuffSum};
    }
    
    int negativeSum(long long sum, int k, vector<int> &arr)
    {
        pair<long long, long long> maxes = getMaxes(arr, sum);
        long long ans = kadane(arr);
        
        if(k == 1)
            return ans % mod;
        
        return max(ans, maxes.first + maxes.second) % mod;
    }
        
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        
        long long sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum >= 0)
            return positiveSum(sum, k, arr);
        
        return negativeSum(sum, k, arr);
    }
};