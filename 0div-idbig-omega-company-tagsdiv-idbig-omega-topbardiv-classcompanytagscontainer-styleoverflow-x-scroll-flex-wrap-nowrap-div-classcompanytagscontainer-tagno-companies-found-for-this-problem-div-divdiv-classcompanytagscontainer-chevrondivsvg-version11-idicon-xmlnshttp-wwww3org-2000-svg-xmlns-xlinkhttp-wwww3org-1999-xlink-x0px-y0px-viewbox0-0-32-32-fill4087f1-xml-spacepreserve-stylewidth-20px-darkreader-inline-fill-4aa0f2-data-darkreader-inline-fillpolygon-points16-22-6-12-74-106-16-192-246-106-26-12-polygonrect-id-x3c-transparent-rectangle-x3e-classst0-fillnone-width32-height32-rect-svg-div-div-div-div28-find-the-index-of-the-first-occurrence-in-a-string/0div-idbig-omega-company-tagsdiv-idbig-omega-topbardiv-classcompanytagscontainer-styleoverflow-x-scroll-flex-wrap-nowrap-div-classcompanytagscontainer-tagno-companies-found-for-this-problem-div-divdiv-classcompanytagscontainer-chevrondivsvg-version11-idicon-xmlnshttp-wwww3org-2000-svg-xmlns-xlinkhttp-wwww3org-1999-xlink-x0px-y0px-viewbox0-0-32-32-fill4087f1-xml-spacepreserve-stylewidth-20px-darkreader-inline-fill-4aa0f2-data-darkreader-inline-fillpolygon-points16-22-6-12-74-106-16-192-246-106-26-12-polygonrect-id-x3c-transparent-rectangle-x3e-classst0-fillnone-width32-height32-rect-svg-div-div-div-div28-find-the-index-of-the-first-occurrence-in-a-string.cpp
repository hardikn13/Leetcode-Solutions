class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int h = haystack.size(), n = needle.size(), j = 0;
        for(int i = 0; i < h; i++)
        {
            if(haystack[i] == needle[j])
            {
                j++;
                if(j == n)
                    return i - n + 1;
            }
            else
            {
                i -= j;
                j = 0;
            }
        }
        
        return -1;
    }
};