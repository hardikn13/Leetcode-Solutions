class Solution {
public:
    bool checkRecord(string s) {
        
        int a = 0, l = 0, t = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'A')
                a++;
            
            if(s[i] == 'L')
            {
                l++;
                
                if(l == 3)
                    t = 1;
                continue;
            }
            
            l = 0;
        }
        
        if(a < 2 && t == 0)
            return true;
        
        return false;
    }
};