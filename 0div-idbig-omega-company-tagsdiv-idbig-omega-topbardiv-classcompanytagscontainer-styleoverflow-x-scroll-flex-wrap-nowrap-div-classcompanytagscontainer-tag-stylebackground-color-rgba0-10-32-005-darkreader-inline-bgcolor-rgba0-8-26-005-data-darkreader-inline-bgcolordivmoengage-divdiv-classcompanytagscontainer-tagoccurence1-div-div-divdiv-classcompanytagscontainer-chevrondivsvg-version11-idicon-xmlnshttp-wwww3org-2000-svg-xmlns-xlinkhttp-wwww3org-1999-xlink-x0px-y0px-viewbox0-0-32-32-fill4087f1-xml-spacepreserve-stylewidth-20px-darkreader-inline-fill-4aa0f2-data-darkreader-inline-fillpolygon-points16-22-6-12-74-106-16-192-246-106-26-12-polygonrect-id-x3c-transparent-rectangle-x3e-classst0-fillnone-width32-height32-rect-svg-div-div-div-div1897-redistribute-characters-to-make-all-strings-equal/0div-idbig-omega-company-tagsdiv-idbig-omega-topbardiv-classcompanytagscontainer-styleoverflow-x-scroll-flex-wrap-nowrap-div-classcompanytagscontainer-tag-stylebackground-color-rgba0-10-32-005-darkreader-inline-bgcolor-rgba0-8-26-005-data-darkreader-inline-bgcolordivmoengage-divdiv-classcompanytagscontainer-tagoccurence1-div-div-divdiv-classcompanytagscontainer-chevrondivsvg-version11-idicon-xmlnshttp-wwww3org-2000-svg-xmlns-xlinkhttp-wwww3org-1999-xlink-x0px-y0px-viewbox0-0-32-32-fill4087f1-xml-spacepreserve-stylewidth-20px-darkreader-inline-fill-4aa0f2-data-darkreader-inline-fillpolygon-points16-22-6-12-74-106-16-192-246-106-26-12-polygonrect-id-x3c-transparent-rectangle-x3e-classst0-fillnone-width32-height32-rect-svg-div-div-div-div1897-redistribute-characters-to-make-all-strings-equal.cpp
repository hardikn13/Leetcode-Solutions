class Solution {
public:
    bool makeEqual(vector<string>& words) {
        
        unordered_map<char, int> mp;
        
        for(auto word : words)
        {
            for(char ch : word)
            {
                mp[ch]++;
            }
        }
        
        for(auto it : mp)
        {
            if(it.second % words.size() != 0)
                return false;
        }
        
        return true;
    }
};