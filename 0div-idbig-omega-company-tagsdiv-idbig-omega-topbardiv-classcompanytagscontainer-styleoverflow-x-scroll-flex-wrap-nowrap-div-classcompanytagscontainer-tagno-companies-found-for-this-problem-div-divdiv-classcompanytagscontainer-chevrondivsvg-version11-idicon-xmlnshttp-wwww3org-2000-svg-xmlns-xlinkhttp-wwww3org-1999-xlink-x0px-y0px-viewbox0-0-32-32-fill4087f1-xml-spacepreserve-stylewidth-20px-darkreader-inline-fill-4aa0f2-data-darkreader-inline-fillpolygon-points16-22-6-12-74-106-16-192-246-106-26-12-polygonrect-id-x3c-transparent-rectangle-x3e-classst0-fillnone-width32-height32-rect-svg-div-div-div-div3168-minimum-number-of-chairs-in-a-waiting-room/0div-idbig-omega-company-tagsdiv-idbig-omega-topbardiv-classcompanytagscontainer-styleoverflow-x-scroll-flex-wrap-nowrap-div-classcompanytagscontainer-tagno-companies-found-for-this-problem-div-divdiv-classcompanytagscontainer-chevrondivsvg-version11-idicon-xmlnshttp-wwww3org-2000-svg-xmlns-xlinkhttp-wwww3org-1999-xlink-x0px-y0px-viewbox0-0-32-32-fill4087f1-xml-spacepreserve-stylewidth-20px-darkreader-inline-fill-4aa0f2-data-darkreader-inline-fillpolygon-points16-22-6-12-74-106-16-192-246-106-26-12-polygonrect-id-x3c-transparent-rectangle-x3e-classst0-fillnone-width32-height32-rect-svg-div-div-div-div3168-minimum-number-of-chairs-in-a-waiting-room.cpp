class Solution {
public:
    int minimumChairs(string s) {
        
        int cnt = 0, ans = INT_MIN;
        for(int i = 0; i< s.size(); i++)
        {
            if(s[i] == 'E')
            {
                cnt++;
                ans = max(ans, cnt);
            }
            else
                cnt--;
        }
        
        return ans;
    }
};