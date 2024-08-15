class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> lastseen(3,-1);
        
        int i = 0, j = 0, ans = 0;
        while(j < n)
        {
            lastseen[s[j] - 'a'] = j;
            ans += (1 + min({lastseen[0], lastseen[1], lastseen[2]}));
            j++;
        }
        
        return ans;
    }
};