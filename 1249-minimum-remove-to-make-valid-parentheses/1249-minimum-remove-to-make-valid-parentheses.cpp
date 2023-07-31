class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> stk;
        int count = 0;
        vector<int> v;
        string str = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                stk.push(make_pair(s[i], i));
            }
            else if(s[i] == ')')
            {
                if(!stk.empty())
                {
                    stk.pop();
                }
                else
                {
                    v.push_back(i);
                    count++;
                }
            }
        }
        
        if(stk.size() > 0){
            while(!stk.empty())
            {
                int a = stk.top().second;
                v.push_back(a);
                stk.pop();
            }
        }
        string ans= "";

        for(int i=0; i<s.size(); i++){
            if(isalpha(s[i])) ans+=s[i];
            else {bool flag = false;
            for(int j =0; j<v.size(); j++){
                if(i == v[j]){
                    flag = true;
                    continue;
                }
            }
            if(flag == false) ans+=s[i];}

        }
        return ans;
    }
};