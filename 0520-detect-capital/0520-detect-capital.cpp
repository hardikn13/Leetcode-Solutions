class Solution {
public:
    bool detectCapitalUse(string word) {
        int h=0,z=0;
        for(int i=0;i<word.size();i++)
        {
            if(word[i]<91)
            {
                if(h==1)
                {
                    return false;
                }
                z=1;
                h=0;
            }
            else if(word[i]>91)
            {
                if(z==1&&i!=1)
                {
                    return false;
                }
                h=1;
                z=0;
            }
        }
        return true;
    }
};