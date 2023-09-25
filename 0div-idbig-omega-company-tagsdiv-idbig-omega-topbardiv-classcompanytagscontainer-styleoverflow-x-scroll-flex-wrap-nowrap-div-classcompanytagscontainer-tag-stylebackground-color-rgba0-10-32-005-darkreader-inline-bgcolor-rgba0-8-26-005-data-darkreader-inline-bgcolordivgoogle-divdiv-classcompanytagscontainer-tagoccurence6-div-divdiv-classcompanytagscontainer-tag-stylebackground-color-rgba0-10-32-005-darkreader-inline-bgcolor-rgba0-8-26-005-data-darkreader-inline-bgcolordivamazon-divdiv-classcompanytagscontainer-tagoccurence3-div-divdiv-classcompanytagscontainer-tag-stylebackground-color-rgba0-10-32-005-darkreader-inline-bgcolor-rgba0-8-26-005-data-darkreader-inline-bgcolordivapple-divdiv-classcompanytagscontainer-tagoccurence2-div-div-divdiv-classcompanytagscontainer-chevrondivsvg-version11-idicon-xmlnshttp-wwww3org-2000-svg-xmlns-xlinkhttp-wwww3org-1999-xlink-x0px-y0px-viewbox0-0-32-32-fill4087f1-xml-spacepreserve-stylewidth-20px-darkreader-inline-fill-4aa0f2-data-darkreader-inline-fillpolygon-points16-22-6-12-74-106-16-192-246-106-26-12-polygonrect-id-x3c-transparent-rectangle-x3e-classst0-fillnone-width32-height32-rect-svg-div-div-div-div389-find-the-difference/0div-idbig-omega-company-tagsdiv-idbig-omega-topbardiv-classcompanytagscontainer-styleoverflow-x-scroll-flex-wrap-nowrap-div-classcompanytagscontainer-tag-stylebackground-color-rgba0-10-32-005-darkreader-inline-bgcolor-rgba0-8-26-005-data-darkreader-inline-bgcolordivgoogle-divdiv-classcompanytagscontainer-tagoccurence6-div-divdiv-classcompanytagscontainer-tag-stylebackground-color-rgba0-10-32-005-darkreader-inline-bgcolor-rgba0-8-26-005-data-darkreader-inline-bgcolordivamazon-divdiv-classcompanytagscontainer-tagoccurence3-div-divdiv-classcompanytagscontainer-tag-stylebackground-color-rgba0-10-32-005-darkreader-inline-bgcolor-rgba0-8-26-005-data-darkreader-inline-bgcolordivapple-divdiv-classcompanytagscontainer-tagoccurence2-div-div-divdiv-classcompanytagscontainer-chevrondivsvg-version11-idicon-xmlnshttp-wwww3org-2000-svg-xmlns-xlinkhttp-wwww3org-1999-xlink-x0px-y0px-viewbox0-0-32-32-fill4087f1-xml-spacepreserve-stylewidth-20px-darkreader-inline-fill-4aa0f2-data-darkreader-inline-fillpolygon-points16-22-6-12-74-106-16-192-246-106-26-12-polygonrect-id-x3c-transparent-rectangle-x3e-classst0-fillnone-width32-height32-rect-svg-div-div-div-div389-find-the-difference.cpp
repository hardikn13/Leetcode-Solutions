class Solution {
public:
    char findTheDifference(string s, string t) {
        
        
        int a = s.size();
        int b = t.size();
        
        if(a == 0)
            return t[0];
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        for(int i = 0; i < a; i++)
        {
            if(s[i] != t[i])
                return t[i];
            
            if(i == a - 1)
                return t[a];
        }
        
        return 0;
    }
};