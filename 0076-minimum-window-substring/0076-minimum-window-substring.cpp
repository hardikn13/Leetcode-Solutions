class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(auto &it : t)
            mp[it]++;

        int i = 0, j = 0;
        int count = 0, sIndex = -1;
        int mini = INT_MAX, n = s.size();

        while(j < n)
        {
            if(mp[s[j]] > 0)
                count++;
            mp[s[j]]--;
            
            while(count == t.size())
            {
                if(j - i + 1 < mini)
                {
                    mini = min(mini, j - i + 1);
                    sIndex = i;
                }
                
                mp[s[i]]++;
                if(mp[s[i]] > 0)
                    count--;

                i++;
            }
            
            j++;
        }

        return sIndex == -1 ? "" : s.substr(sIndex, mini);
    }
};