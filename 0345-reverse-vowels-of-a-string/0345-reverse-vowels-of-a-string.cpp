class Solution {
public:
    
    bool isVowel(char x)
    {
        if( x=='a'|| x=='e'|| x=='i'|| x=='o'|| x=='u' || x=='A'|| x=='E'|| x=='I'|| x=='O'|| x=='U')
        {
            return true;
        }
        return false;
    }
    
    
    string reverseVowels(string s) {
        int start=0, end=s.size()-1;
        while(start<end)
        {
            if(isVowel(s[start])&&isVowel(s[end]))
            {
                char temp=s[start];
                s[start]=s[end];
                s[end]=temp;
                start++;
                end--;
            }
            else if(isVowel(s[start])&&!isVowel(s[end]))
            {
                end--;
            }
            else if(!isVowel(s[start])&&isVowel(s[end]))
            {
                start++;
            }
            else
            {
                start++;
                end--;
            }
            
        }
        return s;
    }
};