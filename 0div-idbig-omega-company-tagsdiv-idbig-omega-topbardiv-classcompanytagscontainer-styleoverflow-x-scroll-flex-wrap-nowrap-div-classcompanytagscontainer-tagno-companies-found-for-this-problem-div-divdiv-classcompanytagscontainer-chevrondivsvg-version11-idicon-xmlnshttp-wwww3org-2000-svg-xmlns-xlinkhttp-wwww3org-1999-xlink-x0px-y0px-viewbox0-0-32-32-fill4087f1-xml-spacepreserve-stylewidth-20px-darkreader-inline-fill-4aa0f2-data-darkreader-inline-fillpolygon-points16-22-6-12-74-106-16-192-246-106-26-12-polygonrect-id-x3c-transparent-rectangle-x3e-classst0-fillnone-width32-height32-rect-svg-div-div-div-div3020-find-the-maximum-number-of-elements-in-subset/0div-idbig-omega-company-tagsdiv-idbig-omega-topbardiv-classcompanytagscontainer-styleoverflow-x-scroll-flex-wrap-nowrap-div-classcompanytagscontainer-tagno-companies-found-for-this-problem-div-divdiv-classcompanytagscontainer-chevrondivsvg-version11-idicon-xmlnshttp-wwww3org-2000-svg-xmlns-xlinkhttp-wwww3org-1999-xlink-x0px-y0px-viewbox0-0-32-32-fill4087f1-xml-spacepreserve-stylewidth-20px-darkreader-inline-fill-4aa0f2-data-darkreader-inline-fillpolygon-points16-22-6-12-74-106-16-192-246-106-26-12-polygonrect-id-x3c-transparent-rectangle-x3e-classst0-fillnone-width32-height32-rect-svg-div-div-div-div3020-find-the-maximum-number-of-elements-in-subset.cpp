class Solution { 
public: 
    int maximumLength(vector<int>& nums) { 
          
        map<int, int> mp;
        int n = nums.size();
        
        for(int i = 0; i < n; i++)
            mp[nums[i]]++;
        
        int ans = 1;
        if(mp[1] % 2 == 1)
            ans = max(ans, mp[1]);
        else
            ans = max(ans, mp[1] - 1);
        
        for(int i = 2; i * i <= 1e9; i++)
        {
            long long num = i;
            int count = 0;
            
            while(num <= 1e9)
            {
                if(mp.find(num) == mp.end())
                    break;
                if(mp[num] >= 2)
                {
                    count += 2;
                    num *= num;
                }
                else
                {
                    count++;
                    break;
                }
            }
            
            if(mp.find(num) == mp.end())
                count--;
            ans = max(ans, count);
        }
        
        return ans;
    }
};