class Solution {
public:
    long long wonderfulSubstrings(string word) {
        
        unordered_map<int, int> mp;
        mp[0] = 1;
        
        long long prefixPattern = 0, ans = 0;
        for(auto c : word)
        {
            prefixPattern ^= (1 << (c - 'a'));
            ans += mp[prefixPattern];
            
            for(auto ch = 'a'; ch <= 'j'; ch++)
            {
                long long oddPattern  = (prefixPattern ^ (1 << (ch - 'a')));
                ans += mp[oddPattern];
            }
            
            mp[prefixPattern]++;
        }
        
        return ans;
    }
};