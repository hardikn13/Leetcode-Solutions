class Solution {
public:
    void f(int ind, string &num, int target, string str, vector<string> &ans, long prevNum, long total)
    {
        if(ind == num.size())
        {
            if(total == target)
                ans.push_back(str);
            return;
        }

        string s = "";
        long sum = 0;
        for(int i = ind; i < num.size(); i++)
        {
            if(i > ind && num[ind] == '0')
                break;

            s += num[i];
            sum = sum * 10 + (num[i] - '0');

            if(ind == 0)
                f(i + 1, num, target, s, ans, sum, sum);
            else
            {
                f(i + 1, num, target, str + '+' + s, ans, sum, total + sum);
                f(i + 1, num, target, str + '-' + s, ans, -sum, total - sum);
                f(i + 1, num, target, str + '*' + s, ans, prevNum * sum, total - prevNum + (prevNum * sum));
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        f(0, num, target, "", ans, 0, 0);
        return ans;
    }
};