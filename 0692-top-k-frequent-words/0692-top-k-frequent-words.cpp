class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for(auto it : words)
        {
            mp[it]++;
        }
        
        
        multimap<int, string, greater<int>> multi;
        for(auto it:mp)
        {
            multi.insert({it.second, it.first});
        }
        
        vector<string> ans;
        int c = 0;
        
        for(auto it:multi)
        {
            ans.push_back(it.second);
            c++;
            if(c == k)
            {
                break;
            }
        }
        return ans;
    }
};