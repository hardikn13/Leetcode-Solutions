int removeDuplicates(int* nums, int numsSize){

    if(numsSize<3)
    {
        return numsSize;
    }
        
    int idx = 2;
    for(int i=2;i<numsSize;++i)
    {
        if(nums[i]!=nums[idx-2])
            nums[idx++] = nums[i];
    }
    return idx;
}