class Solution {
public:
    void findSub(int index, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        ans.push_back(ds);
        for(int j = index; j < arr.size(); j++)
        {
            ds.push_back(arr[j]);
            findSub(j + 1, arr, ans, ds);
            ds.pop_back();
        }
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        findSub(0, nums, ans, ds);
        return ans;
    }
};