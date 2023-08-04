class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int n = nums.size(), cnt = 0;
        int sum = 0;
        map[0] = 1;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            cnt += map[sum - k];
            map[sum]++;
        }
        return cnt;
    }
};