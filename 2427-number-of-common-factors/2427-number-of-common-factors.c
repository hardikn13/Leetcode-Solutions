

int commonFactors(int a, int b){
int count=0,j=0,k=0,ans[a],answer[b];
    int z=a>b?a:b;
    for(int i=1;i<=z;i++)
    {
        if(a%i==0)
        {
            ans[j]=a/i;
            j++;
        }
    }
    int ans1[j];
    for(int i=0;i<j;i++)
    {
        ans1[i]=ans[i];
    }
    for(int i=1;i<=z;i++)
    {
        if(b%i==0)
        {
            answer[k]=b/i;
            k++;
        }
    }
    int answer1[k];
    for(int i=0;i<k;i++)
    {
        answer1[i]=answer[i];
    }
    for(int i=0;i<k;i++)
    {
        for(int t=0;t<j;t++)
        {
            if(ans1[t]==answer1[i])
            {
                count++;
            }
                
        }
    }
    return count;
}