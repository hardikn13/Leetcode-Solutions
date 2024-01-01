class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int satisfied = 0, ind = 0;
        while (ind < s.size() && satisfied < g.size())
        {
            if(s[ind] >= g[satisfied])
                satisfied++;
                
            ind++;
        }
        
        return satisfied;
    }
};