class Solution {
public:
    bool isPossible(vector<int>& nums, vector<int>& changeIndices, int seconds)
    {
        int n = nums.size();
        vector<int> last(n + 1, -1);
        
        for(int i = 0; i < seconds; i++)
            last[changeIndices[i] - 1] = i;
        
        int marked = 0;
        int operations = 0;
        
        for(int i = 0; i < seconds; i++)
        {
            if(i == last[changeIndices[i] - 1])
            {
                if(operations < nums[changeIndices[i] - 1])
                    return false;
                else
                {
                    operations -= nums[changeIndices[i] - 1];
                    marked++;
                }
            }
            else
                operations++;
        }
        
        return (marked == n);
    }
    
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        
        int m = changeIndices.size();
        int low = 0, high = m + 1;
        
        while(low < high)
        {
            int mid = (low + high) / 2;
            
            if(isPossible(nums, changeIndices, mid))
                high = mid;
            else
                low = mid + 1;
        }
        
        if(high == m + 1)
            return -1;
        
        return high;
    }
};