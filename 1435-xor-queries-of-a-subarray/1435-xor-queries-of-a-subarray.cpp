class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i = 1; i < arr.size(); i++)
            arr[i] ^= arr[i - 1];
        
        for(auto &it: queries)
            ans.push_back(it[0] > 0 ? arr[it[0] - 1] ^ arr[it[1]] : arr[it[1]]);
        
        return ans;
    }
};