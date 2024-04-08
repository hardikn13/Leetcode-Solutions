class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        
        int n = nums.size();
        int mini = *min_element(nums.begin(), nums.end());
        
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == mini)
                cnt++;
        }
        
        if(cnt == 1)
            return 1;
        
        int miniNew = mini;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] % miniNew != 0)
                miniNew = min(nums[i] % miniNew, miniNew);
        }
        
        if(miniNew != mini)
            return 1;
        
        return ceil((float)cnt / 2);
    }
};