class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> digits(n);
        int cnt = 0;
        bool flag = true;
        
        for(int i = 0; i < n; i++)
        {
            int num = nums[i];
            
            while(num)
            {
                digits[i].push_back(num % 10);
                num /= 10;
                
                if(flag)
                    cnt++;
            }
            
            flag = false;
        }
        
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
