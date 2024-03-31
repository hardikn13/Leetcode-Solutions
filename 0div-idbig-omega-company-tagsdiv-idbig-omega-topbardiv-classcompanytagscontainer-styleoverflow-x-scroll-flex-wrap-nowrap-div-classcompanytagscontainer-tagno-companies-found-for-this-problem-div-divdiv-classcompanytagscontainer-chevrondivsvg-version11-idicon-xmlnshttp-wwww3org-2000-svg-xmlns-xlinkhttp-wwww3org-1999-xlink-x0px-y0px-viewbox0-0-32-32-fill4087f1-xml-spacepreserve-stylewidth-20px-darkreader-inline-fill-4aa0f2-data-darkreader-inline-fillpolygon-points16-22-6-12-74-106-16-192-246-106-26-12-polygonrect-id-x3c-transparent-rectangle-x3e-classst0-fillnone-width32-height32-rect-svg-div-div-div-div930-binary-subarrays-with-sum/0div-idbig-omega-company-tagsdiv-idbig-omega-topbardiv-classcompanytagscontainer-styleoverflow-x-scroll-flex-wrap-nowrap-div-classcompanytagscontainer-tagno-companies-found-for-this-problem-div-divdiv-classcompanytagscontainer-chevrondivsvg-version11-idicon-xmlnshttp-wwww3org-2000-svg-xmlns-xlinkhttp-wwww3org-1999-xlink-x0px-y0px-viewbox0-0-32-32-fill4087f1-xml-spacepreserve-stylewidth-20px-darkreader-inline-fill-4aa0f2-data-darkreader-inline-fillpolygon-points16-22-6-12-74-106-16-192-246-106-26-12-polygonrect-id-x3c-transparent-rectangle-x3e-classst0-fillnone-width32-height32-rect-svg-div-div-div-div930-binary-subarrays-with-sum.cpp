class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int n = nums.size();
        unordered_map<int, int> freq;
        freq[0] = 1;
        int pref = 0, ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            pref += nums[i];
            
            if(freq.find(pref - goal) != freq.end())
                ans += freq[pref - goal];
            
            freq[pref]++;
        }
        
        return ans;
    }
};