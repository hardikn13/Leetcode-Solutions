class Solution {
public:
    int firstUniqChar(string s) {
        int arr[256]={0};
        for(int i=0;i<s.size();i++)
        {
            arr[s[i]]++;
        }
        for(int i=0;i<s.size();i++)
        {
            if(arr[s[i]]==1)
            {
                return i;
            }
        }
        return -1;
    }
};