class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int arr1[256]={0},arr2[256]={0};
        for(int i=0;i<ransomNote.size();i++)
        {
            arr1[ransomNote[i]]++;
        }
        for(int i=0;i<magazine.size();i++)
        {
            arr2[magazine[i]]++;
        }
        for(int i=0;i<256;i++)
        {
            if(arr1[i]>arr2[i])
            {
                return false;
            }
        }
        return true;
    }
};