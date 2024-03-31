class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        
        vector<int> nums1, nums2;
        
        nums1.push_back(nums[0]);
        nums2.push_back(nums[1]);
        
        int h = nums[0];
        int k = nums[1];
        
        int n = nums.size();
        for(int i = 2; i < n; i++)
        {
            if(h >= k)
            {
                nums1.push_back(nums[i]);
                h = nums[i];
            }
            else
            {
                nums2.push_back(nums[i]);
                k = nums[i];
            }
        }
        
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        
        return nums1;
    }
};