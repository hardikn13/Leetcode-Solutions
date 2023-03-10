

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numssize, int* anssize){
    int *ans;
    
    ans = (int *)malloc(sizeof(int) * numssize * 2);
    *anssize = numssize * 2;
    for (int i = 0; i < numssize; i++)
    {
        ans[i] = nums[i];
        ans[i + numssize] = nums[i];
    }
    return (ans);
}