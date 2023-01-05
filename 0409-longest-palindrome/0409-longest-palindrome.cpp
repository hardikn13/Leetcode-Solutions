class Solution {
public:
    int longestPalindrome(string s) {
        int arr[256]={0};
        for(int i=0;i<s.size();i++)
        {
            arr[s[i]]++;
        }
        int oddgrp=0;
        for(int i=0;i<256;i++)
        {
            if(arr[i]%2!=0)
            {
                arr[i]-=1;
                oddgrp++;
            }
        }
        
        return s.size()-oddgrp+(oddgrp>0);
    }
};