

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeArray(int* nums, int numsSize, int* returnSize){
int* ans=(int*)malloc(sizeof(int)*numsSize);
    *returnSize=numsSize;
    int count=0,cnt=1;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]>=0)
            {
                ans[count]=nums[i];
                count++;
                count++;
            }
        else
            {
                ans[cnt]=nums[i];
                cnt++;
                cnt++;
            }
    }
    return ans;
}