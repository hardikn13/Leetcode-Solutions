class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int n = s.size();
        bool vis[26] = {false};
        int lastSeen[26] = {-1};
        stack<char> st;
        
        for(int i = 0; i < n; i++)
        {
            lastSeen[s[i] - 'a'] = i;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(vis[s[i] - 'a'] == true)
                continue;
            
            while(st.size() > 0 && st.top() > s[i] && i < lastSeen[st.top() - 'a'])
            {
                vis[st.top() - 'a'] = false;
                st.pop();
            }
            
            st.push(s[i]);
            vis[s[i] - 'a'] = true;
        }
        
        string ans = "";
        while(st.size() > 0)
        {
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};