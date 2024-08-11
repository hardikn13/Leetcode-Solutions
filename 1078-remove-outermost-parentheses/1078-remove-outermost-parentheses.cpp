class Solution {
public:
    string removeOuterParentheses(string s) {
        int top = 0;
        stack<char> st;
        string str = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ')')
            {
                st.pop();
                top--;

                if(top)
                    str += ')';
            }
            else
            {
                st.push('(');
                top++;

                if(top > 1)
                    str += '(';
            }
        }

        return str;
    }
};