class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto it = nums.begin() + (n - 1) / 2; 
        nth_element(nums.begin(), it, nums.end()); 
        int median = *it; 
        
        int i = 1;// position for the larger values: start with first odd index
        int j = ((n - 1) & 1) ? n - 2 : n - 1;  // position for the smaller values: start with last even index
        
        for(int l = 0; l < n; l++)
        {
            if(nums[l] > median)
            {
                if(l <= i && (l & 1))
                    continue;       // skip the elements which are  already checked: 1, 3, 5, ..., i
                
                swap(nums[l--], nums[i]);
                i += 2;
            }
            else if(nums[l] < median)
            {
                if(l >= j && (l & 1) == 0)
                    continue;     // skip the elements whcih are checked: j, j + 2, ..., lastEvenIndex
                
                swap(nums[l--], nums[j]);
                j -= 2;
            }
        }
    }
};