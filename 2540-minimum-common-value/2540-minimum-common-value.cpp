class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int l = 0, r = 0;
    while(l < size(nums1) && r < size(nums2)){
        if(nums1[l] < nums2[r]) l++;
        else if(nums1[l] > nums2[r]) r++;
        else return nums1[l];
    }
    return -1;
    }
};