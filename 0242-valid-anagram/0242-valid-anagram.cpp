class Solution {
public:
    bool isAnagram(string s, string t) {
    int temp[26]={0};
        if(s.size()!=t.size())
        {
            return false;
        }
        for(int i=0;i<s.size();i++)
        {
            temp[s[i]-'a']++;
            temp[t[i]-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            if(temp[i]!=0)
            {
                return false;
            }
        }
     return true;
    }
};