class Solution {
public:
    void f(const vector<int>& nums, int index, vector<int> subset,
                         vector<vector<int>>& subsets)
    {
        if(index == nums.size())
        {
            subsets.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        f(nums, index + 1, subset, subsets);
        subset.pop_back();

        f(nums, index + 1, subset, subsets);
    }
    
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        f(nums, 0, {}, subsets);

        int ans = 0;
        for(auto it : subsets)
        {
            int subsetXORTotal = 0;
            for(int num : it)
                subsetXORTotal ^= num;
                
            ans += subsetXORTotal;
        }

        return ans;
    }
};