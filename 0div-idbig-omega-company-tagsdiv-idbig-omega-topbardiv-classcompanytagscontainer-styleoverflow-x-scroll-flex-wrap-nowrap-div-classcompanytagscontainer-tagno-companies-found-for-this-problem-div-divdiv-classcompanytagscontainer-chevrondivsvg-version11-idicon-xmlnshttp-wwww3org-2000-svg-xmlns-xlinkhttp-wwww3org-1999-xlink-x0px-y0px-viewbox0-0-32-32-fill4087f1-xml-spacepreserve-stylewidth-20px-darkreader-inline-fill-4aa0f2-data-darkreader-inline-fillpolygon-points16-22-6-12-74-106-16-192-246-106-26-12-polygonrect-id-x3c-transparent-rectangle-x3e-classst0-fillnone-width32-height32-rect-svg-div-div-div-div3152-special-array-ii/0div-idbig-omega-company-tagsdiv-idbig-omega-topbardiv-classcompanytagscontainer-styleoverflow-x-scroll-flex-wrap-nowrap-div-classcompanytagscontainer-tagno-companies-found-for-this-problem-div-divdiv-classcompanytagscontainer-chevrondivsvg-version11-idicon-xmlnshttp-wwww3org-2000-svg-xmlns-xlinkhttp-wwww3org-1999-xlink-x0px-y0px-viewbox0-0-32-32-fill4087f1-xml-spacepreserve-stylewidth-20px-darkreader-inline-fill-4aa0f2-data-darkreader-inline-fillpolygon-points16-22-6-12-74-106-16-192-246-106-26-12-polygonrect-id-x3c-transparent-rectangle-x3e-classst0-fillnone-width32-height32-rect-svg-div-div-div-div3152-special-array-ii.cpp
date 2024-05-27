class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        
        vector<bool> ans;
        vector<int> decision(n, 0);
        
        for(int i = 0; i < n - 1; i++)
        {
            if((nums[i] % 2) == (nums[i + 1] % 2))
                decision[i + 1] = decision[i] + 1;
            else
                decision[i + 1] = decision[i];
        }
        
        for(auto it : queries)
        {
            if(decision[it[0]] == decision[it[1]])
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        
        return ans;
    }
};