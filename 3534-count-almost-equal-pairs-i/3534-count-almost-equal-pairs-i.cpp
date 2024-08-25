class Solution {
public:
    bool equal(int num1, int num2)
    {
        string s1 = to_string(num1);
        string s2 = to_string(num2);

        while(s1.size() < s2.size())
            s1 = "0" + s1;
        while(s2.size() < s1.size())
            s2 = "0" + s2;

        int n1 = s1.size();
        int n2 = s2.size();
        
        int ans = 0;
        vector<int> v;
        for(int i = 0; i < n1; i++)
        {
            if(s1[i] != s2[i])
            {
                ans++;
                v.push_back(i);
            }

            if(ans > 2)
                return false;
        }
        
        if(ans == 0 || (ans == 2 && s1[v[0]] == s2[v[1]] && s1[v[1]] == s2[v[0]]))
            return true;
        return false;
    }

    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(equal(nums[i], nums[j]))
                    ans++;

        return ans;
    }
};