class Solution {
public:
    int getLucky(string s, int k) {
        
        string ans = "";
        for(int i = 0; i < s.size(); i++)
        {
            int val = s[i] - 'a' + 1;
            ans += to_string(val);
        }

        string t = ans;
        while(k--)
        {
            int sum = 0;
            for(int i = 0; i < t.size(); i++)
                sum += t[i] - '0';

            t = to_string(sum);
        }

        return stoi(t);
    }
};