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
    
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        
        int n = nums.size();
        int m = pattern.size();
        
        string newNums = "", newPattern = "";
        for(int i = 0; i < m; i++)
        {
            if(pattern[i] == 1)
                newPattern += 'a';
            if(pattern[i] == 0)
                newPattern += 's';
            if(pattern[i] == -1)
                newPattern += 'd';
        }
        
        for(int i = 0; i < n - 1; i++)
        {
            if(nums[i + 1] - nums[i] > 0)
                newNums += 'a';
            if(nums[i + 1] - nums[i] == 0)
                newNums += 's';
            if(nums[i + 1] - nums[i] < 0)
                newNums += 'd';
        }
        
        string s = newPattern + '#' + newNums;
        vector<int> v = kmp(s);
        
        int ans = 0;
        for(int i = m; i < v.size(); i++)
        {
            if(v[i] == m)
                ans++;
        }
        
        return ans;
    }
};