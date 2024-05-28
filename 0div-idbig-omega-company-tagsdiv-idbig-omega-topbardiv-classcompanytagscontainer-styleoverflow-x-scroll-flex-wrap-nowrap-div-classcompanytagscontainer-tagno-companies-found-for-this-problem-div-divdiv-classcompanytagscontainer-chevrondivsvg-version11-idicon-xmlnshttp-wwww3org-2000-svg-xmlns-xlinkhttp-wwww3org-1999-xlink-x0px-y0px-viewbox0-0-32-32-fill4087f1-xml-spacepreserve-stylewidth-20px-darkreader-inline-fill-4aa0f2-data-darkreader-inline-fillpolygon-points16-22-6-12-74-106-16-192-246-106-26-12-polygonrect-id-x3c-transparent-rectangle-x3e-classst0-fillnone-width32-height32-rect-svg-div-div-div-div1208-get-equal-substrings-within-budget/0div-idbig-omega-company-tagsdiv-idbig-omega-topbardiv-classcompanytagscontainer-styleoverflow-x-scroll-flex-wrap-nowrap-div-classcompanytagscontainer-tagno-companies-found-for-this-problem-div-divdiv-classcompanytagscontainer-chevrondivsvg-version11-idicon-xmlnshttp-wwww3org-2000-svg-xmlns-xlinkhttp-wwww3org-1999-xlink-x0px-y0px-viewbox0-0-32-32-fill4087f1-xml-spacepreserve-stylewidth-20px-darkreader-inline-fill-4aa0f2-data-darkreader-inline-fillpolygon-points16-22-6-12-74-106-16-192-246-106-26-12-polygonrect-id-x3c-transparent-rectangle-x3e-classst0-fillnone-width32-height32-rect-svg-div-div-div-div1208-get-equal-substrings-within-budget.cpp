class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int n = s.size();
        vector<int> change(n);
        
        for(int i = 0; i < n; i++)
            change[i] = abs(s[i] - t[i]);
        
        int i = 0, j = 0, sum = 0, ans = 0;
        while(j < n)
        {
            sum += change[j];
            
            if(sum <= maxCost)
                ans = max(ans, j - i + 1);
            else if(sum > maxCost)
            {
                while(sum > maxCost)
                {
                    sum -= change[i];
                    i++;
                    
                    if(sum <= maxCost)
                        ans = max(ans, j - i + 1);
                }
            }
            
            j++;
        }
        
        return ans;
    }
};