int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

bool canBeEqual(int* target, int targetSize, int* arr, int arrSize){
qsort(arr, arrSize, sizeof(int), cmpfunc);
qsort(target, targetSize, sizeof(int), cmpfunc);
    for(int i=0;i<targetSize;i++)
    {
        if(target[i]!=arr[i])
        {
            return false;
        }
        if(i==targetSize-1)
        {
            return true;
        }
    }
    return 0;
    
    
    
    // for(int i=0;i<targetSize;i++)
    // {
    //     int k=0;
    //     for(int j=0;j<arrSize;j++)
    //     {
    //         if(target[i]==arr[j])
    //         {
    //             k=1;
    //         }
    //     }
    //     if(k==0)
    //     {
    //         return false;
    //     }
    //     if(i==targetSize-1)
    //     {
    //         return true;
    //     }
    // }
    // return 0;
}