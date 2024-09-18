
bool compare(string a, string b) {
    return a + b > b + a;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for(auto &it : nums)
            s.push_back(to_string(it));
        
        sort(s.begin(), s.end(), compare);
        
        string ans = "";
        for(int i = 0; i < s.size(); i++)
            ans += s[i];
        
        return ans[0] == '0' ? "0" : ans;
    }
};