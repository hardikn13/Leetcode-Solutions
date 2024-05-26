class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        
        int n = nums.size();
        unordered_map<int, int> buckets;
        
        for(int i = 0; i < n; i++)
        {
            int bucket = nums[i] / ((long)valueDiff + 1);
            
            if(nums[i] < 0)
                bucket--;
            
            if(buckets.find(bucket) != buckets.end())
                return true;
            else
            {
                buckets[bucket] = nums[i];
                
                if(buckets.find(bucket - 1) != buckets.end() && buckets[bucket] - buckets[bucket - 1] <= valueDiff)
                    return true;
                if(buckets.find(bucket + 1) != buckets.end() && buckets[bucket + 1] - buckets[bucket] <= valueDiff)
                    return true;
            }
            
            if(buckets.size() > indexDiff)
            {
                int ind = nums[i - indexDiff] / ((long)valueDiff + 1);
                
                if(buckets[ind] < 0)
                    ind--;
                
                buckets.erase(ind);
            }
        }
        
        return false;
    }
};