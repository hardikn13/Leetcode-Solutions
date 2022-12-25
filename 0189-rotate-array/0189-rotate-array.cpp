class Solution {
public:
    void reverseArray(vector<int>& nums, int lo, int hi)
        {
            int l=lo;
            int r=hi;
            while(l<r)
            {
                int temp=nums[l];
                nums[l]=nums[r];
                nums[r]=temp;
                    
                l++;
                r--;
            }
        }
    
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverseArray(nums,0,n-k-1);
        reverseArray(nums,n-k,n-1);
        reverseArray(nums,0,n-1);
    }
};