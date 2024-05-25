class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<int> v;
        unordered_map<int, int> mp;
        for(auto it : nums)
            mp[it]++;
        
        for(auto it : mp)
            if(it.second == 2)
                v.push_back(it.first);
        
        int x = 0;
        for(auto it : v)
            x ^= it;
        
        return x;
    }
};