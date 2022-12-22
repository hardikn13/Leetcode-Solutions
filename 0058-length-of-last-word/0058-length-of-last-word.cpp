class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        int end=s.size()-1;
        while(s[end]==' ')
        {
            end--;
        }
        while(s[end]!=' ')
        {
            count++;
            if(end!=0)
            {
                end--;
            }
            else
            {
                break;
            }
        }
        return count;
    }
};