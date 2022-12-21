int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
int h=nums1Size+nums2Size;
    int *ans=(int*)malloc(sizeof(int)*h);
    for(int i=0;i<nums1Size;i++)
    {
        ans[i]=nums1[i];
    }
    for(int j=0;j<nums2Size;j++)
    {
        ans[nums1Size+j]=nums2[j];
    }
    qsort(ans, h, sizeof(int), cmpfunc);
    if(h%2==0)
    {
    return (double)(ans[(h-1)/2]+ans[h/2])/2;
    }
    else
    {
        return (double)ans[h/2];
    }
    return 0;
}