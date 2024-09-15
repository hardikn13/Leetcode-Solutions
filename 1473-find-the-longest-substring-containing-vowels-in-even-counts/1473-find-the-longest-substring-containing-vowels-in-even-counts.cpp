class Solution {
public:
    int findTheLongestSubstring(string s) {
        
        int n = s.size();
        int ans = 0, xorr = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        unordered_map<char, int> vowels{
            {'a', 1},
            {'e', 2},
            {'i', 4},
            {'o', 8},
            {'u', 16}
        };
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                xorr ^= vowels[s[i]];
            
            if(mp.find(xorr) != mp.end())
                ans = max(ans, i - mp[xorr]);
            else
                mp[xorr] = i;
        }
        
        return ans;
    }
};