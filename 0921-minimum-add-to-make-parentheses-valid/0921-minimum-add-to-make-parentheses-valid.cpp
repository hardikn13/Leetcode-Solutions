class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> stk;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                stk.push(s[i]);
            }
            else
            {
                if(!stk.empty() && stk.top() == '(')
                {
                    stk.pop();
                }
                else
                {
                    stk.push(s[i]);
                }
            }
        }
        int a = 0, b = 0;
        while(!stk.empty())
        {
            if(stk.top() == '(')
            {
                a++;
            }
            else
            {
                b++;
            }
            stk.pop();
        }
        return a + b;
    }
};