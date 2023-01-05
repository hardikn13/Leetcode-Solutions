class Solution {
public:
    int countSegments(string s) {
        int count=0;
        if(s=="")
        {
            return 0;
        }
        int z=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>32)
            {
                z=1;
            }
            if(s[i]==' '&&z==1)
            {
                count++;
                z=0;
            }
            if(i==s.size()-1&&count==0&&z==0)
            {
                return 0;
            }
            if(i==s.size()-1&&s[i]==' ')
            {
                return count;
            }
        }
        return count+1;
    }
};