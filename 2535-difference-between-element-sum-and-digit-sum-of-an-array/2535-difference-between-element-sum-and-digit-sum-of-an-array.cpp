class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum=0,dsum=0,t=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            t=nums[i];
            while(t)
            {
                dsum+=t%10;
                t=t/10;
            }
        }
        return abs(dsum-sum);
    }
};