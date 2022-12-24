class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin(), strs.end());
        string x="";
        for(int i=0;i<strs[0].size();i++)
        {
            if(strs[0][i]==strs[strs.size()-1][i])
            {
                x=x+strs[0][i];
            }
            else
            {
                return x;
            }
        }
        return x;
        
        
        
        
        
        
        
        
        
        
        
        // string str="";
        // for(int i=1;i<strs.size();i++)
        // {
        //     int j=0;
        //     while(j<strs[i].size()&&strs[i][j]==strs[0][j])
        //     {
        //         j++;
        //     }
        //     str=min(str,j);
        // }
        // return str[0].substr(0,str);
    }
};