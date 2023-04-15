class Solution {
public:
    void findSub(int index, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        ans.push_back(ds);
        for(int j = index; j < arr.size(); j++)
        {
            if(j > index && arr[j] == arr[j-1])
            {
                continue;
            }
            ds.push_back(arr[j]);
            findSub(j + 1, arr, ans, ds);
            ds.pop_back();
        }
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        findSub(0, nums, ans, ds);
        return ans;
    }
};