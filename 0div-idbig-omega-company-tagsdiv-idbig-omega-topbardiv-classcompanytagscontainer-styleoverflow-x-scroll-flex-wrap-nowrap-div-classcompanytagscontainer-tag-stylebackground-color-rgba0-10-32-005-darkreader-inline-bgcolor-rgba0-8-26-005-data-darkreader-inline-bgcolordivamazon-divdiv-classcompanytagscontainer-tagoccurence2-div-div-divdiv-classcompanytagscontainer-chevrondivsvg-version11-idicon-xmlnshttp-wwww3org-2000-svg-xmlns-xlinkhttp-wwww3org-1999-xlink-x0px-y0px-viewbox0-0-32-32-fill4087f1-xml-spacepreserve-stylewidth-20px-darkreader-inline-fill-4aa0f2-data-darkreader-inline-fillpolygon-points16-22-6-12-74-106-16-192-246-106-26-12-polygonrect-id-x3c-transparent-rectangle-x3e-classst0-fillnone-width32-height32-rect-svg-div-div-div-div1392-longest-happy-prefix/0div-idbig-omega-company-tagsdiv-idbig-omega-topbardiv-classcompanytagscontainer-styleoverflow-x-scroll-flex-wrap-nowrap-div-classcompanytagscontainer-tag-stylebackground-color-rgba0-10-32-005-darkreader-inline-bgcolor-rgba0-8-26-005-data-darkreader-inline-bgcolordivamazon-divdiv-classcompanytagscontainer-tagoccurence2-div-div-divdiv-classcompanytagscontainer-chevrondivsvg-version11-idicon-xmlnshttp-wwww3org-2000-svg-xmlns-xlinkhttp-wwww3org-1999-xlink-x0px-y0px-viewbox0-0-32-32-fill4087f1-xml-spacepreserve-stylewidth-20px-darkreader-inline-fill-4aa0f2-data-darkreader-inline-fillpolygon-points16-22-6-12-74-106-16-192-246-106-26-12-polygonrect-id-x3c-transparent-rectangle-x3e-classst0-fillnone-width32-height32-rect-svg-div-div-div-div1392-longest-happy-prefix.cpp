class Solution {
public:
    vector<int> kmp(string s)
    {
        int n = s.size();
        vector<int> lps(n, 0);
        
        for(int i = 1; i < n; i++)
        {
            int prevInd = lps[i - 1];
            
            while(prevInd > 0 && s[i] != s[prevInd])
                prevInd = lps[prevInd - 1];
            
            lps[i] = prevInd + (s[i] == s[prevInd] ? 1 : 0);
        }
        
        return lps;
    }
    
    string longestPrefix(string s) {
        
        int n = s.size();
        vector<int> lps = kmp(s);
        int t = lps[n - 1];
        
        string ans = "";
        for(int i = n - t; i < n; i++)
        {
            ans += s[i];
        }
        
        return ans;
    }
};