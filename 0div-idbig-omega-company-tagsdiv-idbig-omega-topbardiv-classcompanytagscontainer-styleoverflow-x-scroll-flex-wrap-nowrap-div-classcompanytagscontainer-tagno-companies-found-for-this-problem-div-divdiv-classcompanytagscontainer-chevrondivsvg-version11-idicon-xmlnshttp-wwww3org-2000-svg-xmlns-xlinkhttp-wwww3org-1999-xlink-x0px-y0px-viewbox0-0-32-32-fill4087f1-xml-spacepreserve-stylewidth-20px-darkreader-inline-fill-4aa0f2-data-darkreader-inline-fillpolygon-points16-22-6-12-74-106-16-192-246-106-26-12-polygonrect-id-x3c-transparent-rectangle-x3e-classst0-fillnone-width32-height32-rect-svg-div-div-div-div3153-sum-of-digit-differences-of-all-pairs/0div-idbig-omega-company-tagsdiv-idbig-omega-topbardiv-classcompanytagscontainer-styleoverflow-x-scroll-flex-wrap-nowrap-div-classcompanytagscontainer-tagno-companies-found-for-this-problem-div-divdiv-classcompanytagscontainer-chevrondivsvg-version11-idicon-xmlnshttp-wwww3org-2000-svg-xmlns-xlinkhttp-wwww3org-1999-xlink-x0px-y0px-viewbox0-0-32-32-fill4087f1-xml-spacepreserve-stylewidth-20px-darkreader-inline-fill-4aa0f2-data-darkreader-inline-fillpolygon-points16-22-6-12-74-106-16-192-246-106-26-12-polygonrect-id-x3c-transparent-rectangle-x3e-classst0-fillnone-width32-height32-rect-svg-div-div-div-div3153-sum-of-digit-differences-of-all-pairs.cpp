class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> digits(n);
        
        for(int i = 0; i < n; i++)
        {
            int num = nums[i];
            
            while(num)
            {
                digits[i].push_back(num % 10);
                num /= 10;
            }
        }
        
        int cnt = digits[0].size();
        long long ans = 0;
        for(int i = 0; i < cnt; i++)
        {
            vector<int> count(10, 0);
            
            for(int j = 0; j < n; j++)
            {
                if(i < digits[j].size())
                    count[digits[j][i]]++;
                else
                    count[0]++;
            }
            
            for(int i = 0; i < 10; i++)
                for(int j = i + 1; j < 10; j++)
                    ans += (long long)count[i] * count[j];
        }
        
        return ans;
    }
};
