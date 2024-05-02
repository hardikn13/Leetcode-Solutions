class Solution {
public:
    void f(int ind, int temp, int &ans, vector<int> &uniqueChar)
    {
        ans = max(ans, __builtin_popcount(temp));
        
        for(int i = ind; i < uniqueChar.size(); i++)
        {
            if((temp & uniqueChar[i]) == 0)
                f(i + 1, temp | uniqueChar[i], ans, uniqueChar);
        }
    }
    
    int maxLength(vector<string>& arr) {
        
        vector<int> uniqueChar;
        
        for(string &s : arr)
        {
            unordered_set<char> st(begin(s), end(s));
            
            if(st.size() != s.size())
                continue;
            
            int val = 0;
            for(char &ch : s)
                val |= (1 << (ch - 'a'));
            
            uniqueChar.push_back(val);
        }
        
        int ans = 0;
        f(0, 0, ans, uniqueChar);
        
        return ans;
    }
};