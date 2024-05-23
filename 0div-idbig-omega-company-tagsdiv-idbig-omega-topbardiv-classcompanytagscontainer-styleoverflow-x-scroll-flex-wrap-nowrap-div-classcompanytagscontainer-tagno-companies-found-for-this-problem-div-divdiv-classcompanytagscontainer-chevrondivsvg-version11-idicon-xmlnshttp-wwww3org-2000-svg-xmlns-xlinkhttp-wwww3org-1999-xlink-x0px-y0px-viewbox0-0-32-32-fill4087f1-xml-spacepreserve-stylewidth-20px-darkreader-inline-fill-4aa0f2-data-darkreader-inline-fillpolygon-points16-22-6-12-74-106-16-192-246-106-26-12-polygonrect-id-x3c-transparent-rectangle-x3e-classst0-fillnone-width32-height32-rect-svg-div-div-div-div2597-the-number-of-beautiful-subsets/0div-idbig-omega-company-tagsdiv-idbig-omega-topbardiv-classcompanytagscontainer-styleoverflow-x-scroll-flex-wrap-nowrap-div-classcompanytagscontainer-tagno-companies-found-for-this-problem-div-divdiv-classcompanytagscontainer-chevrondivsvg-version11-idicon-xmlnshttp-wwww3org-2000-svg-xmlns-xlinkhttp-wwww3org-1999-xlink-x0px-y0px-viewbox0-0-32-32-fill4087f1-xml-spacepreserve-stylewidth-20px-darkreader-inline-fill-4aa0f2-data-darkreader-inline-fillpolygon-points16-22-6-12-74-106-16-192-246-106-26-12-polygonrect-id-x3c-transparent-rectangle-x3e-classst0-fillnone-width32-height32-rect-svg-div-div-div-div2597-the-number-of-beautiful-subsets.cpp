class Solution {
public:
    void f(int ind, int &ans, vector<int> &nums, int k, unordered_map<int, int> &mp)
    {
        if(ind == nums.size())
            ans++;
        else
        {
            if(!mp[nums[ind] - k] && !mp[nums[ind] + k])
            {
                mp[nums[ind]]++;
                f(ind + 1, ans, nums, k, mp);
                mp[nums[ind]]--;
            }
            
            f(ind + 1, ans, nums, k, mp);
        }
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mp;
        f(0, ans, nums, k, mp);
        
        return ans - 1;
    }
};