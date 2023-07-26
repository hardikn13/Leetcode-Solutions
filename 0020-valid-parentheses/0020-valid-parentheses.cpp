class Solution {
public:
    bool isValid(string s) {
        stack <char> stk;
        if(s.size() == 1)
        {
            return 0;
        }
        int z = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                stk.push(s[i]);
                z++;
            }
            else if(s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if(z == 0)
                {
                    return 0;
                }
                if(s[i] == ')' && stk.top() == '(')
                {
                    stk.pop();
                    z--;
                }
                else if(s[i] == ']' && stk.top() == '[')
                {
                    stk.pop();
                    z--;
                }
                else if(s[i] == '}' && stk.top() == '{')
                {
                    stk.pop();
                    z--;
                }
                else
                {
                    return 0;
                }
            }
        }
        if(stk.empty() == 0)
        {
            return 0;
        }
        return 1;
    }
};