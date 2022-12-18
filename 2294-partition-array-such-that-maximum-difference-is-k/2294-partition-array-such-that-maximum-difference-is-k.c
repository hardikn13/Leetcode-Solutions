int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


int partitionArray(int* nums, int numsSize, int k){
qsort(nums, numsSize, sizeof(int), cmpfunc);
    int h=0,t=nums[0];
    for(int i=1;i<numsSize;i++)
    {
        if(nums[i]-t<=k)
        {
            continue;
        }
        else
        {
            t=nums[i];
            h++;
        }
    }
    return h+1;
}