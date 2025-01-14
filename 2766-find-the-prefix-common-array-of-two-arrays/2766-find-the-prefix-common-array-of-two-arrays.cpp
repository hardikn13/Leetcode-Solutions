class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {

        int n = a.size();
        vector<int> v(n + 1, 0), ans(n, 0);
               
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            v[a[i]]++;

            if(v[a[i]] == 2)
                cnt++;

            v[b[i]]++;
            if(v[b[i]] == 2)
                cnt++;     
            ans[i] = cnt;
        }
        
        return ans;
    }
};