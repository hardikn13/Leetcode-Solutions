class Solution {
public:
    char repeatedCharacter(string s) {
        int arr[256]={0};
        for(int i=0;i<s.size();i++)
        {
            arr[s[i]]++;
            if(arr[s[i]]>=2)
            {
                return s[i];
            }
        }
        return 0;
    }
};