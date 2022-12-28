class Solution {
public:
    char findTheDifference(string s, string t) {
        int arr1[256]={0},arr2[256]={0},sum1=0,sum2=0;
        for(int i=0;i<s.size();i++)
        {
            arr1[s[i]]=s[i];
            sum1+=s[i];
        }
        for(int i=0;i<t.size();i++)
        {
            arr2[t[i]]=t[i];
            sum2+=t[i];
        }
        return sum2-sum1;
    }
};