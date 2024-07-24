class Solution {
public:
    static bool cmp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)
    {
        if(a.first == b.first)
        {
            return a.second.first < b.second.first;
        }
        return a.first < b.first;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, pair<int, int>>> v;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int num = nums[i];
            int add = 0;
            int t = 0;
            while(num || t == 0)
            {
                int next = num % 10;
                int temp = mapping[next];
                add += pow(10, t) * (temp);
                t++;
                num /= 10;
            }

            v.push_back({add, {i, nums[i]}});
        }

        sort(v.begin(), v.end(), cmp);
        vector<int> ans;

        for(int i = 0; i < n; i++)
            ans.push_back(v[i].second.second);

        return ans;
    }
};