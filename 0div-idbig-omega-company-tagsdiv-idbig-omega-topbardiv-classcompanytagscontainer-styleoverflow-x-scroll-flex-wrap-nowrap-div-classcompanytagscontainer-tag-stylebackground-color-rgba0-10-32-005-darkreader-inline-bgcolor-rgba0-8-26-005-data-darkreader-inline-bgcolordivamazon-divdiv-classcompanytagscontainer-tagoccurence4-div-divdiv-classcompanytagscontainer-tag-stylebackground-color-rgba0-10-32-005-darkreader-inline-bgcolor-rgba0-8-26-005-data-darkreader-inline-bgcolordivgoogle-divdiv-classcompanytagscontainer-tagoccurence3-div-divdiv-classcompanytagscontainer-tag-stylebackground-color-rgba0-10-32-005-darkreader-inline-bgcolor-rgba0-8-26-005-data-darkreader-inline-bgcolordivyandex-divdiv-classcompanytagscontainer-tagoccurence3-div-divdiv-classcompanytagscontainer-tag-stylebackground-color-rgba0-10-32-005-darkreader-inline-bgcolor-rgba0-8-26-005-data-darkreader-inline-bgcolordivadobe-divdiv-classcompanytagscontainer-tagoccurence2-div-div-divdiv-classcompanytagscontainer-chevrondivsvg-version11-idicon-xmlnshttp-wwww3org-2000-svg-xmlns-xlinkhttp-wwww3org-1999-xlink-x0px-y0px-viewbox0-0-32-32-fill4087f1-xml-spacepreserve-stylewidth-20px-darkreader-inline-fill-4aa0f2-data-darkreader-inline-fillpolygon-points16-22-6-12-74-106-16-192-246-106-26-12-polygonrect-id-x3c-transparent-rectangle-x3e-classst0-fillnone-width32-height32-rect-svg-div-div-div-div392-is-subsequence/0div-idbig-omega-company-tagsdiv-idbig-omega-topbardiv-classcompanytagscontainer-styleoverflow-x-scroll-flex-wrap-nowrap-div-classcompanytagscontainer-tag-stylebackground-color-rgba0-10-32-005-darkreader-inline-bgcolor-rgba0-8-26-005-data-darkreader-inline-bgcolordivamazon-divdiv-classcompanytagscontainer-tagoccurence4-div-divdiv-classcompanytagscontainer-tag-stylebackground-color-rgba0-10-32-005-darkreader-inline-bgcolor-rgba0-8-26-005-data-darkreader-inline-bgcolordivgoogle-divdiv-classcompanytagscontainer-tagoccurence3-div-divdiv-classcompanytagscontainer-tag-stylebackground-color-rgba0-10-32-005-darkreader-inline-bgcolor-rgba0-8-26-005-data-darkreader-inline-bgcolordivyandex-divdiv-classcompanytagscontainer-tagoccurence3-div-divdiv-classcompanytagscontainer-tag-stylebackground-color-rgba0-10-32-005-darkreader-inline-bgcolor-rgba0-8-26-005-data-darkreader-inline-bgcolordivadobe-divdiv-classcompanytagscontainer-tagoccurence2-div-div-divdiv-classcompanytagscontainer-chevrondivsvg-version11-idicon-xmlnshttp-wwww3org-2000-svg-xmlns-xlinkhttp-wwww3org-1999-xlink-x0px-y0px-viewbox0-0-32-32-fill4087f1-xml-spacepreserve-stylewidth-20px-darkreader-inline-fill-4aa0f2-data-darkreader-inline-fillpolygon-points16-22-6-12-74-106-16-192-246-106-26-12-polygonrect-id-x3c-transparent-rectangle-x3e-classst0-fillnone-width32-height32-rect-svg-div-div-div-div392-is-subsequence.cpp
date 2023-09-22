class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int s1 = s.size();
        int s2 = t.size();
        
        int a = 0;
        for(int i = 0; i < s2; i++)
        {
            if(t[i] == s[a])
                a++;
        }
        
        if(a == s1)
            return true;
        
        return false;
    }
};