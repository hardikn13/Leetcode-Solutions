class Solution {
public:
    int minSteps(string s, string t) {
        
        int n = s.size();
        vector<int> hash(256, 0);
        for(int i = 0; i < n; i++)
        {
            hash[s[i] - 'a']++;
        }
        
        for(int i = 0; i < n; i++)
        {
            hash[t[i] - 'a']--;
            if(hash[t[i] - 'a'] < 0)
                hash[t[i] - 'a'] = 0;
        }
        
        int sum = accumulate(hash.begin(), hash.end(), 0);
        return sum;
    }
};