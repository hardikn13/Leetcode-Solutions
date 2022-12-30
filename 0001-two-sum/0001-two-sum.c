int* twoSum(int* nums, int numsSize, int target, int* returnSize){
int *ans = (int*)malloc(sizeof(int)*numsSize);
    *returnSize=2;
    for(int i=0;i<numsSize;i++)
    {
        for(int j=0;j<numsSize&&j!=i;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                ans[1]=j;
                ans[0]=i;
            }
        }
    }
    return ans;
}