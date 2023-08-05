class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        
        multimap<int, char> multi;
        for(auto it : mp)
        {
            multi.insert({it.second, it.first});
        }
        
        string str = "";
        for(auto it = multi.rbegin(); it != multi.rend(); it++)
        {
            for(int i = 0; i < it->first; i++)
            {
                str.push_back(it->second);
            }
        }
        return str;
    }
};