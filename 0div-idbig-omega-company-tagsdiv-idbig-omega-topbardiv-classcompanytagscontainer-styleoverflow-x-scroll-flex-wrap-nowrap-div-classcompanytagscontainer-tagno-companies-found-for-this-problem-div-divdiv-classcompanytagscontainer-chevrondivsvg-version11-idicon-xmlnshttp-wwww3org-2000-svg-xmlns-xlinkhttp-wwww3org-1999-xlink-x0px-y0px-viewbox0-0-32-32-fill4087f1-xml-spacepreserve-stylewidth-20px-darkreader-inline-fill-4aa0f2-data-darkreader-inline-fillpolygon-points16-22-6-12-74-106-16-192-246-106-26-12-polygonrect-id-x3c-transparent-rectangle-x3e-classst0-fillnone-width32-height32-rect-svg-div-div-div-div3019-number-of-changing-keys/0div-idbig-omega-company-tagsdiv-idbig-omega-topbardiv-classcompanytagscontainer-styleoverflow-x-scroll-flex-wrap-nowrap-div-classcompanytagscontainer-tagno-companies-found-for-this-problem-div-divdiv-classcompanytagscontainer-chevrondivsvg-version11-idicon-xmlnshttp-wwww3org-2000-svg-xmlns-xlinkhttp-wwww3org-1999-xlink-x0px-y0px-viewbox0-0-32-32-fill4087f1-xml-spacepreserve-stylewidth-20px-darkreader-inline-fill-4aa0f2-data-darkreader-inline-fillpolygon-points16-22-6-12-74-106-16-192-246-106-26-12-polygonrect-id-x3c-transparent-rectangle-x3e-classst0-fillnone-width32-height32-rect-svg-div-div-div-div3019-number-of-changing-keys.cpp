class Solution {
public:
    int countKeyChanges(string s) {
        
        int cnt = 0, diff = s[0];
        for(int i = 1; i < s.size(); i++)
        {
            if(abs(s[i] - diff) != 32 && s[i] != diff)
            {
                cnt++;
            }
            diff = s[i];
        }
        
        return cnt;
    }
};