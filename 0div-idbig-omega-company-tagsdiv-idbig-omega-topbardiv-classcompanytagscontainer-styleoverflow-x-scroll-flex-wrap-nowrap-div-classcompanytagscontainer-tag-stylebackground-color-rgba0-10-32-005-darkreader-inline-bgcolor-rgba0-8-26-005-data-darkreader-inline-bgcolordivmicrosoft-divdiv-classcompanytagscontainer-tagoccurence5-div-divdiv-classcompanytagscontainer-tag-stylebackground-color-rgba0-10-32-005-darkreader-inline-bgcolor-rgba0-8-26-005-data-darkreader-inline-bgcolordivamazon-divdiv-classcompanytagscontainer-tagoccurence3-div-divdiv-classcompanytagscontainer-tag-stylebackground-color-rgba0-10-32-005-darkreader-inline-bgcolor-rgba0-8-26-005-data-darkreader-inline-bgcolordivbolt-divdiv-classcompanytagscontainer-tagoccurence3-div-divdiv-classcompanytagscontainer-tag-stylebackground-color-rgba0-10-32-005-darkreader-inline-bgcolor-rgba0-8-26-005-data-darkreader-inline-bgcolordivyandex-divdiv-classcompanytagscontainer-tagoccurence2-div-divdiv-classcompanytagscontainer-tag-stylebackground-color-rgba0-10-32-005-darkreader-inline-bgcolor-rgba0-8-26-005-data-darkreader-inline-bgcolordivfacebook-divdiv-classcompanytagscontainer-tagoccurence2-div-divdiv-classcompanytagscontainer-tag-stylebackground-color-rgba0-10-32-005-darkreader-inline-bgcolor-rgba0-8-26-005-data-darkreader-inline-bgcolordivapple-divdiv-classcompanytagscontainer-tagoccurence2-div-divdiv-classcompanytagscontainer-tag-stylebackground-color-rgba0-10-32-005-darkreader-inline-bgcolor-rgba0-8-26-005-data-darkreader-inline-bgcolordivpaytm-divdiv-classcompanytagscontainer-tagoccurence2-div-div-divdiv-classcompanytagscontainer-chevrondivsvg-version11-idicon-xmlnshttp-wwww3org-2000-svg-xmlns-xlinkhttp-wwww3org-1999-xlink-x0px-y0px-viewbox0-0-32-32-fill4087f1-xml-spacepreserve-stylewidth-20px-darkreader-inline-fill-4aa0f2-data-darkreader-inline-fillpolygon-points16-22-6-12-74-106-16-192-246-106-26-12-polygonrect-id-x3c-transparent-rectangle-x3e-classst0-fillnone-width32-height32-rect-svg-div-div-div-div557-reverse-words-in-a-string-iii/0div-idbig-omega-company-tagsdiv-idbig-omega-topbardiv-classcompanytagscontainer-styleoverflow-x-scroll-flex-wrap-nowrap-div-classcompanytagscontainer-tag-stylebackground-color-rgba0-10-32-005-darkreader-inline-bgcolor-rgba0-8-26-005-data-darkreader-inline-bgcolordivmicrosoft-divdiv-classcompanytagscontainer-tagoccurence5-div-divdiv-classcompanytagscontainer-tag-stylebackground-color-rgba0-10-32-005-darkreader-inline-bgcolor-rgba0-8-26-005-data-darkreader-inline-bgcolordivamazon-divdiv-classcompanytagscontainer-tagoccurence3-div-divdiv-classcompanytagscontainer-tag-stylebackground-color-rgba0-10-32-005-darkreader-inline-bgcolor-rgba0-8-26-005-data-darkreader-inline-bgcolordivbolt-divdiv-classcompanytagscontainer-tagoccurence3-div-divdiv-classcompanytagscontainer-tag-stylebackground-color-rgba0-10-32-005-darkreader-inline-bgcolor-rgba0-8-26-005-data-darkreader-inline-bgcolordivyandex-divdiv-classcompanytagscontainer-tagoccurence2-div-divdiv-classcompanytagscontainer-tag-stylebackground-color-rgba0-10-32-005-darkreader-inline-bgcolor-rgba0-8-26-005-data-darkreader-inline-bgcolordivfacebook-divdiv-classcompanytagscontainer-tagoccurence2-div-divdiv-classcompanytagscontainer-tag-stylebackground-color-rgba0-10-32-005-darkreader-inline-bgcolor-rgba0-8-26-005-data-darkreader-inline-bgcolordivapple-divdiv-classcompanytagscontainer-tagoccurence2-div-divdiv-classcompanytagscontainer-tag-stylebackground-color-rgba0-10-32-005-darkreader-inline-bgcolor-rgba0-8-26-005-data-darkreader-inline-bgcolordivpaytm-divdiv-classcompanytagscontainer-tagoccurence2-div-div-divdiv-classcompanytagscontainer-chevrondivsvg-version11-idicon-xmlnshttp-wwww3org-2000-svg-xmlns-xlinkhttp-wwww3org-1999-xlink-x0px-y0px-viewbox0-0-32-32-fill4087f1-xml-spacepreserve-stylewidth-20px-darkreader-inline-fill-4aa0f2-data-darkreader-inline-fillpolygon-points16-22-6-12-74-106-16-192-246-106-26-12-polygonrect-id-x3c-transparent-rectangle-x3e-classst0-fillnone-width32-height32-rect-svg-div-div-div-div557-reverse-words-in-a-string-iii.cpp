class Solution {
public:
    string reverseWords(string s) {
        
        int t = 0, p = 0, z = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                reverse(s.begin() + t, s.begin() + p);
                t = p;
                t++;
                z = 1;
            }            
            p++;
        }
        
        if(z == 0)
        {
            reverse(s.begin(), s.end());
            return s;
        }
        
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] == ' ')
            {
                reverse(s.begin() + i + 1, s.end());
                break;
            }
        }
        return s;
    }
};