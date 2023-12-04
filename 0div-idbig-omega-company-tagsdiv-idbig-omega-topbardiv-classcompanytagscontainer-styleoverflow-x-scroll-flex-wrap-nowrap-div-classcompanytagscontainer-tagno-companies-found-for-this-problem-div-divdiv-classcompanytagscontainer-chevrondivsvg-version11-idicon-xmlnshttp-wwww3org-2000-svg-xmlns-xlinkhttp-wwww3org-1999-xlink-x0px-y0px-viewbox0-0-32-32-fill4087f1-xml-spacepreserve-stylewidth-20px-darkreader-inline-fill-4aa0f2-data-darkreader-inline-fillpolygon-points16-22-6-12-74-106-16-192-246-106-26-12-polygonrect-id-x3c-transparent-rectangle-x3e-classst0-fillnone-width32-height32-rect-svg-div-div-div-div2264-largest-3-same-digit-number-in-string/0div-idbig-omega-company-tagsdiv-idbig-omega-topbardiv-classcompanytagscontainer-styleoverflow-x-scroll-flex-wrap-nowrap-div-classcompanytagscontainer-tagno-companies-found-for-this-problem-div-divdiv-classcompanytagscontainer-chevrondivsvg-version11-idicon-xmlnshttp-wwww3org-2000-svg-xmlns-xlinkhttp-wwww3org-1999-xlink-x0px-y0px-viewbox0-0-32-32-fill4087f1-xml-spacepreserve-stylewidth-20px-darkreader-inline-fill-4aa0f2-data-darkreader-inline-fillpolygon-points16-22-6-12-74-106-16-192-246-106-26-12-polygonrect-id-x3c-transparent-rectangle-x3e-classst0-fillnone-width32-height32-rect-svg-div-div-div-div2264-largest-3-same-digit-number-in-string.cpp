class Solution {
public:
    string largestGoodInteger(string num) {
        
        unordered_map<int, int> mp;
        int n = num.size();
        
        for(int i = 1; i < n - 1; i++)
        {
            if(num[i - 1] == num[i] && num[i] == num[i + 1])
            {
                mp[num[i]] = num[i];
            }
        }
        
        string s = "";
        
        if(mp.empty())
            return s;
        
        int ans = 0;
        for(auto it : mp)
        {
            ans = max(ans, mp[it.second]);
        }
        
        s += ans;
        s += ans;
        s += ans;
        
        return s;
    }
};