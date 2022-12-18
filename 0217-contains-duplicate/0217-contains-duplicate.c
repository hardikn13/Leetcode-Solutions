int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

bool containsDuplicate(int* nums, int numsSize){
qsort(nums, numsSize, sizeof(int), cmpfunc);
    for(int i=0;i<numsSize-1;i++)
    {
        if(nums[i]==nums[i+1])
        {
            return true;
        }
        if(i==numsSize-2)
        {
            return false;
        }
    }
    return 0;
    
    
    // for(int i=0;i<numsSize;i++)
    // {
    //     int count=1;
    //     for(int j=numsSize-1;j>=0&&i!=j;j--)
    //     {
    //         if(nums[i]==nums[j])
    //         {
    //             count++;
    //         }
    //     }
    //     if(count>1)
    //     {
    //         return true;
    //     }
    //     if(count==1&&i==numsSize-1)
    //     {
    //         return false;
    //     }
    // }
    // return 0;
}