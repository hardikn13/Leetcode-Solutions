class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int> ans;
        
        if(words.empty())
            return ans;
        
        int n = s.size();
        int m = words.size();
        int size = words[0].size();

        unordered_map<string, int> mp, temp;
        for(auto it : words)
            mp[it]++;
        temp = mp;

        for(int i = 0; i < n - m * size + 1; i++)
        {
            mp = temp;
            bool isValid = true;
            
            int j = 0;
            while(j < m * size)
            {
                if(mp[s.substr(i + j, size)] > 0)
                    mp[s.substr(i + j, size)]--;
                else
                {
                    isValid = false;
                    break;
                }
                
                j += size;
            }

            if(isValid)
                ans.push_back(i);
        }

        return ans;
    }
};