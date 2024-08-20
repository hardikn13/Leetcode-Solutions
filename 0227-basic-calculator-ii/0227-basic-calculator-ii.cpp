class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> st;

        int num = 0;
        char prevOp = '+';

        for(int i = 0; i < n; i++)
        {
            if(isdigit(s[i]))
                num = num * 10 + (s[i] - '0');
            
            if(s[i] != ' ' && !isdigit(s[i]) || i == n-1)
            {
                if(prevOp == '+')
                    st.push(num);
                else if(prevOp == '-')
                    st.push(-num);
                else if(prevOp == '/')
                {
                    int x = st.top();
                    st.pop();
                    st.push(x / num);
                }
                else if(prevOp == '*')
                {
                    int x = st.top();
                    st.pop();
                    st.push(num * x);
                }
                
                num = 0;
                prevOp = s[i];
            }
        }
        
        int ans = 0;
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};