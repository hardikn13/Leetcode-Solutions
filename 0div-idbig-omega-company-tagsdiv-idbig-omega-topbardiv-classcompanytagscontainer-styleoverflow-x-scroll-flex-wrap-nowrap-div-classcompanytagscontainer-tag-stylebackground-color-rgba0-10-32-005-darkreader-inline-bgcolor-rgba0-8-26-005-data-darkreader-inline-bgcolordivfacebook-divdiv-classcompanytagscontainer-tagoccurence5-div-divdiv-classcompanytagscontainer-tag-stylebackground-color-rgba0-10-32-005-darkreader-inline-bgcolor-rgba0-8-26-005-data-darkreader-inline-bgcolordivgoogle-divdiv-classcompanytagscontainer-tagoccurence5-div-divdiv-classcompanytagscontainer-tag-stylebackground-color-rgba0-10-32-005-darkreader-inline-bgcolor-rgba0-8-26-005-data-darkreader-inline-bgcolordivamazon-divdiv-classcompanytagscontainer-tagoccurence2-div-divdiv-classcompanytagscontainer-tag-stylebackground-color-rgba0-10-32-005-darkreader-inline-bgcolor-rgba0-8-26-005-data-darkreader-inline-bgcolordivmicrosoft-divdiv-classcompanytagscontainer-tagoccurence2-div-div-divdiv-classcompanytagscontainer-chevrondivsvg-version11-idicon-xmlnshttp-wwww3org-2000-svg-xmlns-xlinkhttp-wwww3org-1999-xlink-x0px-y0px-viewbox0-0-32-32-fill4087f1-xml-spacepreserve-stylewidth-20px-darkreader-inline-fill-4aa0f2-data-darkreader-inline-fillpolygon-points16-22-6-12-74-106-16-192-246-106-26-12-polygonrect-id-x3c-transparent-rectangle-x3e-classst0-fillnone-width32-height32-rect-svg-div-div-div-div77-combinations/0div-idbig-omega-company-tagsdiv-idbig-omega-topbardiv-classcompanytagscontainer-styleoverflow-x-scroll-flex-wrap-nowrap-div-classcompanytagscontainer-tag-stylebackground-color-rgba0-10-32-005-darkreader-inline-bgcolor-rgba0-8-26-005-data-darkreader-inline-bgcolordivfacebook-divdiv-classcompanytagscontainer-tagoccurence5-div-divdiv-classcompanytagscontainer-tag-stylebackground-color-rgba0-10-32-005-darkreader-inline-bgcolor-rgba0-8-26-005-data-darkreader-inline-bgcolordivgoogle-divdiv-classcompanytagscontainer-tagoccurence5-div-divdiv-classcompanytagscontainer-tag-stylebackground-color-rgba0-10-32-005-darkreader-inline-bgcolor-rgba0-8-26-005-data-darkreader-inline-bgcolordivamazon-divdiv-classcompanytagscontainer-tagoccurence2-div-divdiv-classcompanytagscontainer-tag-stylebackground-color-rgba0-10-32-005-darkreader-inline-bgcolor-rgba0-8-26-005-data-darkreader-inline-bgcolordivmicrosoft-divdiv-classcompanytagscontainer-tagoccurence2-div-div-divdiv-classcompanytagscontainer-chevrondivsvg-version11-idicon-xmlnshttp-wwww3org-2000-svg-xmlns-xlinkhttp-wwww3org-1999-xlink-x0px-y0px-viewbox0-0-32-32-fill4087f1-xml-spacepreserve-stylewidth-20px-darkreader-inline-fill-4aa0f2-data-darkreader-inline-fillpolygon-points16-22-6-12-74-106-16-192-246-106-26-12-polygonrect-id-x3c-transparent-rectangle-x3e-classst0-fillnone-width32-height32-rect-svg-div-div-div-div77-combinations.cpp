class Solution {
public:
    void f(int num, vector<int> &ds, vector<vector<int>> &ans, int k, int n)
    {
        if(num == n + 1)
        {
            if(k == 0)
                ans.push_back(ds);
            return;
        }
        
        f(num + 1, ds, ans, k, n);
        if(k > 0)
        {
            ds.push_back(num);
            f(num + 1, ds, ans, k - 1, n);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> ans;
        vector<int> ds;
        f(1, ds, ans, k, n);
        
        return ans;
    }
};