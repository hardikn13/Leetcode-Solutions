class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        vector<int> minFreq(26, INT_MAX);
        
        for(auto it : words)
        {
            vector<int> freq(26, 0);
            for(char ch : it)
                freq[ch - 'a']++;
            
            for(int i = 0; i < 26; ++i)
                minFreq[i] = min(minFreq[i], freq[i]);
        }
        
        vector<string> ans;
        for(int i = 0; i < 26; ++i)
        {
            while(minFreq[i] > 0)
            {
                ans.push_back(string(1, 'a' + i));
                minFreq[i]--;
            }
        }
        
        return ans;
    }
};
