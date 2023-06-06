class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int count=0;
        string str = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i]!='-')
                count++;
        }
        if(count == 0)
            return str;
        char arr[count];
        int q = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i]!='-')
            {
                arr[q] = toupper(s[i]);
                q++;
            }
        }
        int z = count % k;
        int j = 0;
        if(z == 0)
        {
            j = count/k;
        }
        else
        {
            j = count/k + 1;
        }
        int t = 0;
        for(int i = 0; i < j; i++)
        {
            if(i == 0 && z != 0)
            {
                for(; t < z; t++)
                {
                    str.push_back(char(arr[t]));
                }
            }
            else
            {
                int p = t + k;
                for(; t < p; t++)
                {
                    str.push_back(char(arr[t]));
                }
            }
            str.append("-");
        }
        cout<<str<<endl;
        return str.substr(0, str.length()-1);
    }
};