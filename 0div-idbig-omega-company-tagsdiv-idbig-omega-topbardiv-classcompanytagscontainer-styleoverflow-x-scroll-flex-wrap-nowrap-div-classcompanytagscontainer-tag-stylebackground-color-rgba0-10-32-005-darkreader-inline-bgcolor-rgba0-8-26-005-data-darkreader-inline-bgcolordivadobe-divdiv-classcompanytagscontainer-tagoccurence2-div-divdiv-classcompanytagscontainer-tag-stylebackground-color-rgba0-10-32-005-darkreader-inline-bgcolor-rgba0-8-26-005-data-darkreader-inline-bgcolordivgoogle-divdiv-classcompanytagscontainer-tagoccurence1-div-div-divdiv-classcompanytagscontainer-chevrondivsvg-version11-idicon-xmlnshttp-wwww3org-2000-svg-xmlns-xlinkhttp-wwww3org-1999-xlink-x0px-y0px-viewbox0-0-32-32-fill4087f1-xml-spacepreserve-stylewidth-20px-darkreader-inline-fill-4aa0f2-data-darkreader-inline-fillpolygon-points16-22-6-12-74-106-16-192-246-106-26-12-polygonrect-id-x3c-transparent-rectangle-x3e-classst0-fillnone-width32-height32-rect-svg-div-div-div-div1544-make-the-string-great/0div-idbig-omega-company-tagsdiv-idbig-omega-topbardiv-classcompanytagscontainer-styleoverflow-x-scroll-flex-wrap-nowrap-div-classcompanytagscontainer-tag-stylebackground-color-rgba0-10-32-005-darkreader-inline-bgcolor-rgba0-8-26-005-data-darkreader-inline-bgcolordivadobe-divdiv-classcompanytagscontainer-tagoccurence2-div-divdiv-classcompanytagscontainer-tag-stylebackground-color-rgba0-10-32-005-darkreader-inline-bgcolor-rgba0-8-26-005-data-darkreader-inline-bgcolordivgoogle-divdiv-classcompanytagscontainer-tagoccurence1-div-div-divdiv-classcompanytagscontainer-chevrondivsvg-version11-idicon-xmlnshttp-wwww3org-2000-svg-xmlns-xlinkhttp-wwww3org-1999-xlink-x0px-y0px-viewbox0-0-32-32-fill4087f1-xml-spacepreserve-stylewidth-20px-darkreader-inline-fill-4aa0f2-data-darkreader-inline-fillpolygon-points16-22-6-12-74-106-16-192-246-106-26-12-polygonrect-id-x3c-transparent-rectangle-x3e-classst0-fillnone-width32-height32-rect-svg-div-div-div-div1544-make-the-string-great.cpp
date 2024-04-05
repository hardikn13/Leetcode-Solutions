class Solution {
public:
    string makeGood(string s) {
        
        int n = s.size();
        for(int i = 0; i < n - 1; i++)
        {
            int p1 = int(s[i + 1]);
            int p2 = int(s[i]);
            if(abs(p1 - p2) == 32)
            {
                s.erase(s.begin() + i + 1);
                s.erase(s.begin() + i);
                i = -1;
            }
        }
        
        return s;
    }
};