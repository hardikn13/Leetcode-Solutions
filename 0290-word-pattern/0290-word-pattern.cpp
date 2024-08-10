class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> mp;
        map<string, char> pm;
        int j = 0;
        for(int i = 0; i < pattern.size(); i++)
        {
            string str = "";
            while(j < s.size() && s[j] != ' ')
            {
                str += s[j];
                j++;
            }
            j++;

            if(pm.find(str) != pm.end() && pm[str] != pattern[i])
                return false;

            if(mp.find(pattern[i]) != mp.end())
            {
                if(mp[pattern[i]] != str)
                    return false;
            }

            if(j >= s.size() && i != pattern.size() - 1)
                return false;
            
            mp[pattern[i]] = str;
            pm[str] = pattern[i];
        }
        
        if(j < s.size())
            return false;

        return true;
    }
};