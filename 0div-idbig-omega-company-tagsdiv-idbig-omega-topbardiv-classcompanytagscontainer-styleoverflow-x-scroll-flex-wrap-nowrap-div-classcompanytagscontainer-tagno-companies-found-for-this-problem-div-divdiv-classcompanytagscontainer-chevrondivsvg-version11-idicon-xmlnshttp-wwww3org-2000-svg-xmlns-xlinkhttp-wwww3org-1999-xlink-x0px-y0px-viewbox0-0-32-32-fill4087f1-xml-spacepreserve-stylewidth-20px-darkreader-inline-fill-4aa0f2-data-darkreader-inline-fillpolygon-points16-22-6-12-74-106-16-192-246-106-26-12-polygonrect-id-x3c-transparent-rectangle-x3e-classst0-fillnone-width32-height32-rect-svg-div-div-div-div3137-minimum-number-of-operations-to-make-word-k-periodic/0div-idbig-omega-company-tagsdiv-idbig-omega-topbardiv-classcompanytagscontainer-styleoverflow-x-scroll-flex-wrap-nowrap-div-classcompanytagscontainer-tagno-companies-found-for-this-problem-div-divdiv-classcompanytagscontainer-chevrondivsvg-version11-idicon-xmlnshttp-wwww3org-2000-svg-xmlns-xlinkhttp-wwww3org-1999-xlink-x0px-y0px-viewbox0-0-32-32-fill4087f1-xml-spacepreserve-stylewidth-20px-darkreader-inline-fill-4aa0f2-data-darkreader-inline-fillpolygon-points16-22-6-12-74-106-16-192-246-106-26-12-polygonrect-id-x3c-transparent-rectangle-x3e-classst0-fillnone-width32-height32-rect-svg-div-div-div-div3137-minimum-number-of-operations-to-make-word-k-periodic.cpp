class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        
        int n = word.size();
        unordered_map<string, int> mp;
        
        int i = 0, j = k - 1;
        
        while(j < n)
        {
            mp[word.substr(i, k)]++;
            i += k;
            j += k;
        }
        
        int maxi = 0, total = 0;
        for(auto it : mp)
        {
            maxi = max(maxi, it.second);
            total += it.second;
        }
        
        return total - maxi;
    }
};
