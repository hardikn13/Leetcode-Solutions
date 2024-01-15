class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        
        int n = s.size();
        int p = a.size();
        int q = b.size();
        
        vector<int> fora;
        vector<int> forb;
        set<int> st;
        vector<int> ans;
        
        int j = 0, t = 0, cnt = 0, count = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == a[j])
            {
                cnt++;
                j++;
                if(cnt == p)
                {
                    fora.push_back(i - p + 1);
                    j = 0;
                    cnt = 0;
                }
            }
            else
            {
                j = 0;
                cnt = 0;
                if(s[i] == a[0])
                {
                    cnt = 1;
                    j = 1;
                }
            }
            
            if(s[i] == b[t])
            {
                count++;
                t++;
                if(count == q)
                {
                    forb.push_back(i - q + 1);
                    t = 0;
                    count = 0;
                }
            }
            else
            {
                t = 0;
                count = 0;
                if(s[i] == b[0])
                {
                    count = 1;
                    t = 1;
                }
            }
        }
        
        for(auto it : fora)
        {
            if(it <= n - p && it >=0)
            {
                for(auto tt : forb)
                {
                    if(abs(tt - it) <= k)
                    {
                        st.insert(it);
                        break;
                    }
                }
            }
        }
        
        for(auto it : st)
            ans.push_back(it);
        
        return ans;
    }
};