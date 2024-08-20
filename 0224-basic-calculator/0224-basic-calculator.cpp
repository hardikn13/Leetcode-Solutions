class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> st;
        
        int num = 0, ans = 0, sign = 1;
        for(int i = 0; i < n; i++)
        {
            if(isdigit(s[i]))
                num = num * 10 + (s[i] - '0');
            else if(s[i] == '+' || s[i] == '-')
            {
                ans += (num * sign);
                num = 0;

                if(s[i] == '+')
                    sign = 1;
                else
                    sign = -1;
            }
            else if(s[i] == '(')
            {
                st.push(ans);
                st.push(sign);

                ans = 0;
                sign = 1;
            }
            else if(s[i] == ')')
            {
                ans += (num * sign);
                num = 0;

                ans *= st.top();
                st.pop();
                ans += st.top();
                st.pop();
            }
        }

        ans += (num * sign);
        return ans;
    }
};