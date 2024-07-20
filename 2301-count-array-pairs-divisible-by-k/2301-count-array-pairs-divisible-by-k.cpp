class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<long long, long long> gcdCount;
        long long ans = 0;
        
        for(long long i = 0; i < nums.size(); i++)
        {
            long long currgcd = __gcd(nums[i], k);
            for(auto &[gc_d, count] : gcdCount)
                if((currgcd * gc_d) % k == 0)
                    ans += count;
            gcdCount[currgcd]++;
        }
        
        return ans;
    }
};