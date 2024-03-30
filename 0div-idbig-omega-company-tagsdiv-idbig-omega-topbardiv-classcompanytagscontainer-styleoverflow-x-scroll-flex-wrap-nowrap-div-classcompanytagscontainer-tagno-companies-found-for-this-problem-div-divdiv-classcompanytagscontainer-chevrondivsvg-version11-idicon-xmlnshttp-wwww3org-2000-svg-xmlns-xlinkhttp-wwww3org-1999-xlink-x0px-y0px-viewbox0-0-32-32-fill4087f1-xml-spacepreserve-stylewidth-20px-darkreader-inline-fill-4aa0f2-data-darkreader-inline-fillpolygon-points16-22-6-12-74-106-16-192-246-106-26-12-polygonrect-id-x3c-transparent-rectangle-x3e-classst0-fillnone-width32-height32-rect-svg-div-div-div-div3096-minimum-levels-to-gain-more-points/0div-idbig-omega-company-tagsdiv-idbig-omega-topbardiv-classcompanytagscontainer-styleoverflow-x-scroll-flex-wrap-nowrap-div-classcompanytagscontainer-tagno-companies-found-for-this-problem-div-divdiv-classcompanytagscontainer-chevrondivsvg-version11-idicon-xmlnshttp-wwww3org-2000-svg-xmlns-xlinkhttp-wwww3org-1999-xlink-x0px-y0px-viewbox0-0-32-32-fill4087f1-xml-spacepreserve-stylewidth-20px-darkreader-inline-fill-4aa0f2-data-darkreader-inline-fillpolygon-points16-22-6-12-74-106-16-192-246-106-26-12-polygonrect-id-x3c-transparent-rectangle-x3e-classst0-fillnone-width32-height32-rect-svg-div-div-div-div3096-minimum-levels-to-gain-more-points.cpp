class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        
        int n = possible.size();
        vector<int> pref(n, 0);
        vector<int> suff(n, 0);
        
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(possible[i] == 0)
                sum -= 1;
            else
                sum += 1;
            
            pref[i] = sum;
        }
        
        sum = 0;
        suff[n - 1] = 0;
        for(int i = n - 2; i >= 0; i--)
        {
            if(possible[i + 1] == 0)
                sum -= 1;
            else
                sum += 1;
            
            suff[i] = sum;
        }
        
        for(int i = 0; i < n - 1; i++)
        {
            if(pref[i] > suff[i])
                return i + 1;
        }
        
        return -1;
    }
};