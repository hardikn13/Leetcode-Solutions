class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        
        vector<int> hash(26, 0);
        
        for(int i = 0; i < n; i++)
        {
            hash[word[i] - 'a']++;
        }
        
        sort(hash.begin(), hash.end(), greater<int>());
        
        int ans = 0, a = 1, t = 8;
        for(int i = 0; i < 26; i++)
        {
            ans += a * hash[i];
            t--;
            if(t == 0)
            {
                a++;
                t = 8;
            }
        }
        
        return ans;
    }
};