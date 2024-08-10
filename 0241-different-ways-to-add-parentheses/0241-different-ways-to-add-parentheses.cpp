class Solution {
public:
    vector<int> diffWaysToComputeHelper(string expression, unordered_map<string, vector<int>> &dp)
    {
        if(dp.find(expression) != dp.end())
            return dp[expression];

        vector<int> ans;
        int n = expression.size();
        
        for(int i = 0; i < n; i++)
        {
            if(expression[i] == '*' || expression[i] == '+' || expression[i] == '-')
            {
                vector<int> left = diffWaysToComputeHelper(expression.substr(0, i), dp);
                vector<int> right = diffWaysToComputeHelper(expression.substr(i + 1), dp);

                for(int k : left)
                {
                    for(int j : right)
                    {
                        if(expression[i] == '*')
                            ans.push_back(k * j);
                        else if(expression[i] == '+')
                            ans.push_back(k + j);
                        else
                            ans.push_back(k - j);
                    }
                }
            }
        }
        
        if(ans.empty())
            ans.push_back(stoi(expression));

        dp[expression] = ans;
        return ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string, vector<int>> dp;
        return diffWaysToComputeHelper(expression, dp);
    }
};
