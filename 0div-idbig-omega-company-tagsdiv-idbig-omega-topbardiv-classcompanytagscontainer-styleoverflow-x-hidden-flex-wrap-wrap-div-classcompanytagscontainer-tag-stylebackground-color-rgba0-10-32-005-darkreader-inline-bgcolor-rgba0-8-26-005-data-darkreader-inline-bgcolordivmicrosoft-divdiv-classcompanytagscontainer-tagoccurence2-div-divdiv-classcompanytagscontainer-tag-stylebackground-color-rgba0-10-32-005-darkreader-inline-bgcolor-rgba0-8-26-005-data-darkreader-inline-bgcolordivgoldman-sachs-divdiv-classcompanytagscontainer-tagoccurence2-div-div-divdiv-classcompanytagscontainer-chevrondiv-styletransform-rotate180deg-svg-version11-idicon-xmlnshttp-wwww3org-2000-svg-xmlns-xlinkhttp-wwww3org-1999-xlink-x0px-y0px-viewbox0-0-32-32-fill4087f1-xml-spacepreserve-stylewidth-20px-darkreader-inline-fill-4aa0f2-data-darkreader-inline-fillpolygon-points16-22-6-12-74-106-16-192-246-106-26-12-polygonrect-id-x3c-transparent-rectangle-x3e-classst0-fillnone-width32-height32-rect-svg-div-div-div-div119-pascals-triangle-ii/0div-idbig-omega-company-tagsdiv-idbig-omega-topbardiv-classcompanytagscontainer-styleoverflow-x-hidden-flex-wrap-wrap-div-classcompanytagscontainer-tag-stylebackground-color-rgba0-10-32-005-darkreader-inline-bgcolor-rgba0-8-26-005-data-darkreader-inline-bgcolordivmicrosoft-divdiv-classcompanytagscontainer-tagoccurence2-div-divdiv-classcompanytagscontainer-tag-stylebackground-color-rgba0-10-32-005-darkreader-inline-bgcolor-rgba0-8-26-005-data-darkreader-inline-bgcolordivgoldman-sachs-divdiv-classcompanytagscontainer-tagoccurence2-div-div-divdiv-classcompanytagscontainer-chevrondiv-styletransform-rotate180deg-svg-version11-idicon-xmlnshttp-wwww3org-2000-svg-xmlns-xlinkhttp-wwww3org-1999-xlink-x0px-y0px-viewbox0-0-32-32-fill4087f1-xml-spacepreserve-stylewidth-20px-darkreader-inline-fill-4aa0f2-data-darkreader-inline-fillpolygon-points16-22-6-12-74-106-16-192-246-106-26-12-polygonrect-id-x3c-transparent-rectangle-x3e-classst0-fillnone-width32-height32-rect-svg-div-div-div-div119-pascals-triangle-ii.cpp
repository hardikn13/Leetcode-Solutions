class Solution {
public:
    vector<int> getRow(int n) {
        
        long long ans = 1;
        vector<int> ds;
        ds.push_back(1);
        n += 1;
        
        for(int i = 1; i < n; i++)
        {
            ans *= (n - i);
            ans /= i;
            ds.push_back(ans);
        }
        
        return ds;
    }
};