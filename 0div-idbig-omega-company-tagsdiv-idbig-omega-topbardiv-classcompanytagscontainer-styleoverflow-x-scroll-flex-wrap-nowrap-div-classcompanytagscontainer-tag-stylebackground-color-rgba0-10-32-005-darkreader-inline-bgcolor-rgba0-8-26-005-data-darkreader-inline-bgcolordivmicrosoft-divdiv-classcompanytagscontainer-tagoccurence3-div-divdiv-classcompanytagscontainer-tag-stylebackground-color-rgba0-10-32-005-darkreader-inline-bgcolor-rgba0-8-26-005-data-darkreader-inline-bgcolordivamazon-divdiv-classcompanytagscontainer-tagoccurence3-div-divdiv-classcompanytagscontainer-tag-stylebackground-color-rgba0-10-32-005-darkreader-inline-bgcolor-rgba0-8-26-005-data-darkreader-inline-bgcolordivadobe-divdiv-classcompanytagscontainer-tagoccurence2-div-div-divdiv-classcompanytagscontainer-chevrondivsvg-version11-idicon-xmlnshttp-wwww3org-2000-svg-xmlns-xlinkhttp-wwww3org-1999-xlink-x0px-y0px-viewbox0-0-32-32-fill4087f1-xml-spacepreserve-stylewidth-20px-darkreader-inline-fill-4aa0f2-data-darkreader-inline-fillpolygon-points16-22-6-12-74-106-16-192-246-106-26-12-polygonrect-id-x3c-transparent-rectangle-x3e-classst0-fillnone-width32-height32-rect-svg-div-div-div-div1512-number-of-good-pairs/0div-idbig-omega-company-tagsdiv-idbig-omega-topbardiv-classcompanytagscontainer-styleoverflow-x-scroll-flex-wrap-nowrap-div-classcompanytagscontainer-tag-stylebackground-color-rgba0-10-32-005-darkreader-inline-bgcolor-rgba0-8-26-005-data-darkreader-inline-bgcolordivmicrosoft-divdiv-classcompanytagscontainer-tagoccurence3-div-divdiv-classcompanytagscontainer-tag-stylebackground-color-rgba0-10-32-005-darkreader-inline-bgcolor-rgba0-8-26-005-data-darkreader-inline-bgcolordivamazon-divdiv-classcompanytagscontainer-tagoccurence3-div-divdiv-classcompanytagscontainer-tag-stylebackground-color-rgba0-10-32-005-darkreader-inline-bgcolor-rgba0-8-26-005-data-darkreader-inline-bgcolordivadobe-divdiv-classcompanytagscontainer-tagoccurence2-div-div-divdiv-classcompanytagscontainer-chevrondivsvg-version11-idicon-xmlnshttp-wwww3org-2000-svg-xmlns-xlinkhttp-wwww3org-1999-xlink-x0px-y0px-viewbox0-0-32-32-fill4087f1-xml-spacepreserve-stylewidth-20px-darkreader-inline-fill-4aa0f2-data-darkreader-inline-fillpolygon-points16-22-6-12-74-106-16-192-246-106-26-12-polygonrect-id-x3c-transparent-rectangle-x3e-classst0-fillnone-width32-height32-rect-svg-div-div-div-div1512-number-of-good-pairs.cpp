class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int n = nums.size();
        int cnt = 0;
        
        map<int, int> hash;
        
        for(int i = 0; i < n; i++)
            hash[nums[i]]++;
        
        for(auto it : hash)
            cnt += it.second * (it.second - 1) / 2;
        
        return cnt;
    }
};