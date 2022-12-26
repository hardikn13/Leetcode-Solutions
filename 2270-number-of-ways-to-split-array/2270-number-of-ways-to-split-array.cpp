class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int splits=0;
        double sumL=0,sumR=0;
        for(int i=0;i<nums.size();i++)
        {
            sumR+=nums[i];
        }
        for(int j=0;j<nums.size()-1;j++)
        {
            sumL+=nums[j];
            sumR-=nums[j];
            if(sumL>=sumR)
            {
                splits++;
            }
        }
        return splits;
    }
};