class Solution {

    private:
    bool checkEqual(int a[26], int b[26])
    {
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
                return false;
        }
        return true;
    }
    
    
    public:
    bool checkInclusion(string s1, string s2) {
        int temp[26]={0};
        for(int i=0;i<s1.size();i++)
        {
            temp[s1[i]-'a']++;
        }
        
        int i=0;
        int windowSize=s1.size();
        
        int temp1[26]={0};
        while(i<windowSize&&i<s2.size())
        {
            temp1[s2[i]-'a']++;
            i++;
        }
        
        if(checkEqual(temp, temp1))
        {
            return true;
        }
        
        
        while(i<s2.size())
        {
            temp1[s2[i-windowSize]-'a']--;
            temp1[s2[i]-'a']++;
            i++;
            if(checkEqual(temp, temp1))
            {
            return true;
            }
        
        }
        

        return false;
    }
};