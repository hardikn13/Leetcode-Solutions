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
    
    int minimumTimeToInitialState(string word, int k) {
        
        vector<int> lps = kmp(word);
        int n = word.size();
        int maxLps = lps[n - 1];
        
        while(maxLps > 0 && (n - maxLps) % k != 0)
            maxLps = lps[maxLps - 1];
        
        return (n - maxLps) % k == 0 ? (n - maxLps) / k : (n + k - 1) / k;
    }
};