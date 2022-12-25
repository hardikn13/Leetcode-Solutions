class Solution {
public:
    string removeDuplicates(string s) {
        int i=0;
        while(s.size()>1&&i!=s.size()-1)
        {
            if(s[i]==s[i+1])
            {
                s.erase(i,2);
                if(i==0)
                {
                    i=-1;
                }
                else
                {
                    i=i-2;
                }
            }
            i++;
        }
        return s;
    }
};