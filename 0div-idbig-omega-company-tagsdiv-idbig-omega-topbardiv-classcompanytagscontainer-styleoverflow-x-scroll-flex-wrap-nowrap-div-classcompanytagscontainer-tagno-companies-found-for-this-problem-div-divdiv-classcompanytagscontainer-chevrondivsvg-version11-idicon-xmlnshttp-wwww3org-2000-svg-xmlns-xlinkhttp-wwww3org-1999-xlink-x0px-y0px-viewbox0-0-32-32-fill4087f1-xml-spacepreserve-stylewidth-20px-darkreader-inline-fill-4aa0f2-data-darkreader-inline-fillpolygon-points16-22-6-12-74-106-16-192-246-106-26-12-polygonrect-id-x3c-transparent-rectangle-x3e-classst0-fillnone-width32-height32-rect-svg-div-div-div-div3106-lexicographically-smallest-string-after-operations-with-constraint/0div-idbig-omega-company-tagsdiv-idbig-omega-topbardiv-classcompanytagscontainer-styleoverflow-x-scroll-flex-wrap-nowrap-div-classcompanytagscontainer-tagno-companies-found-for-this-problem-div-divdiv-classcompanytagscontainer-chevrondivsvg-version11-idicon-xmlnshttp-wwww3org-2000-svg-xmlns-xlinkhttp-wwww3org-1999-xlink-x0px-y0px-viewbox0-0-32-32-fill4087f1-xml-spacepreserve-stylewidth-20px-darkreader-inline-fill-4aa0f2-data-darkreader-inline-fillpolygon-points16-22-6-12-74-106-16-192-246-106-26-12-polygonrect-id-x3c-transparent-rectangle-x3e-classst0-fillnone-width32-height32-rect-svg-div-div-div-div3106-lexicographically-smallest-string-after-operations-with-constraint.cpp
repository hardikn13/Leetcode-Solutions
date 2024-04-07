class Solution {
public:
    string getSmallestString(string s, int k) {
        
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            int dist = min(s[i] - 'a', 26 - s[i] + 'a');
            if(dist <= k)
            {
                s[i] = 'a';
                k -= dist;
            }
            else
            {
                s[i] = (char)(s[i] - k);
                k = 0;
            }
        }
        
        return s;
    }
};