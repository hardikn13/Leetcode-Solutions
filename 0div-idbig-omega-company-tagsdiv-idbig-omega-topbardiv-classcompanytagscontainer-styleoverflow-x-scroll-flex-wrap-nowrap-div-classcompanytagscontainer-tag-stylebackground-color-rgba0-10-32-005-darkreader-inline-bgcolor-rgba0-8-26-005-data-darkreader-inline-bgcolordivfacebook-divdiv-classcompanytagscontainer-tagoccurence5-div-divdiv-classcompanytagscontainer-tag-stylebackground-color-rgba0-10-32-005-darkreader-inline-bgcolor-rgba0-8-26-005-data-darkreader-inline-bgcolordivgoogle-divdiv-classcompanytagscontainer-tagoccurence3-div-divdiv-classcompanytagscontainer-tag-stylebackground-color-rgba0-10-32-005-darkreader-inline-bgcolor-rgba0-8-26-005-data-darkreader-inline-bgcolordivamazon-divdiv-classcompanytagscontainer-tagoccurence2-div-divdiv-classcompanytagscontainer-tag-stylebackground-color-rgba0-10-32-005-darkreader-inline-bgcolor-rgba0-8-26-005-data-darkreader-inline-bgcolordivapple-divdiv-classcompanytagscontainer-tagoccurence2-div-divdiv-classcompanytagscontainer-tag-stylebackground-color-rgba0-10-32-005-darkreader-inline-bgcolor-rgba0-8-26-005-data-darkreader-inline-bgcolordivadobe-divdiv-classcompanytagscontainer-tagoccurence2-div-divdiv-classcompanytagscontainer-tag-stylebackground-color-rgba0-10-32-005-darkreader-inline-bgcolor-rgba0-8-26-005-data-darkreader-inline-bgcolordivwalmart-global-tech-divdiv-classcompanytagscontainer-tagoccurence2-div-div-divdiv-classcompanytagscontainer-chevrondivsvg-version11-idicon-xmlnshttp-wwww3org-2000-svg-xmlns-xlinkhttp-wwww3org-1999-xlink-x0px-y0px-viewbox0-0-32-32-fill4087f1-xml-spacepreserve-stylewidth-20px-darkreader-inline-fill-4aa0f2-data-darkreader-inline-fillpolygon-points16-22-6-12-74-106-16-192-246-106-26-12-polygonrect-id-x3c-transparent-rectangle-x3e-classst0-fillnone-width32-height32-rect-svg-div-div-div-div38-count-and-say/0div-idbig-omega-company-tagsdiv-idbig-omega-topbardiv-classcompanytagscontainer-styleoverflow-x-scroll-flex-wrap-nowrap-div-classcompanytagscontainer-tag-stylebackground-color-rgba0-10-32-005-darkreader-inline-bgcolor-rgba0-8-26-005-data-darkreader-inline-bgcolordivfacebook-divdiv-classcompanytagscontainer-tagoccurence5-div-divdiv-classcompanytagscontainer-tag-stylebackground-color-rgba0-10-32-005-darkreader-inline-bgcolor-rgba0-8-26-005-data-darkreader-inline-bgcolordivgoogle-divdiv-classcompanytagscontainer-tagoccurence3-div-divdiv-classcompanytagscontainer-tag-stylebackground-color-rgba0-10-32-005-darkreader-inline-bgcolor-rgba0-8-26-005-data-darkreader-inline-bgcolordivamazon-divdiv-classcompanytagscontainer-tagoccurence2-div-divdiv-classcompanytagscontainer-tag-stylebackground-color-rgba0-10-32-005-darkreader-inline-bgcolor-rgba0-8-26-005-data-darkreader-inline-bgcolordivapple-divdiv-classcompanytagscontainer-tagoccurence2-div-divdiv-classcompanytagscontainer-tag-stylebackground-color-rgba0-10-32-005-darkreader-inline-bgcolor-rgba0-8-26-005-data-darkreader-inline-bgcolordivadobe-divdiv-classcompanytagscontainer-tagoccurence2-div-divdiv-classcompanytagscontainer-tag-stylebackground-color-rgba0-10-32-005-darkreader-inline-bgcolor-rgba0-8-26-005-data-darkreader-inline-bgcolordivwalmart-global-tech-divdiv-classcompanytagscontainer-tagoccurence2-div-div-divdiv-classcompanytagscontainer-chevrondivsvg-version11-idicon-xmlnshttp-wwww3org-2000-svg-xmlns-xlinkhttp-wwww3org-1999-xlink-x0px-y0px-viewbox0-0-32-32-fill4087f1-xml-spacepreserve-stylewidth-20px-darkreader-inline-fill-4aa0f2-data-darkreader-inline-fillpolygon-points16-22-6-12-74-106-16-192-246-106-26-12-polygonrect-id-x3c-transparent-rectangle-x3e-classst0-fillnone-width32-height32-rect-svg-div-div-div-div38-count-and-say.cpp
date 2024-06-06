class Solution {
public:
    string countAndSay(int n) {
        
        if (n == 1)
            return "1";
        
        string ans = countAndSay(n - 1);
        
        string str = "";
        int i = 0;
        int j = 0;
        while(j < ans.size())
        {
            while(j < ans.size() && ans[i] == ans[j])
                j++;
            
            str += to_string(j - i);
            str += ans[i];
            i = j;
        }
        
        return str;
    }
};
