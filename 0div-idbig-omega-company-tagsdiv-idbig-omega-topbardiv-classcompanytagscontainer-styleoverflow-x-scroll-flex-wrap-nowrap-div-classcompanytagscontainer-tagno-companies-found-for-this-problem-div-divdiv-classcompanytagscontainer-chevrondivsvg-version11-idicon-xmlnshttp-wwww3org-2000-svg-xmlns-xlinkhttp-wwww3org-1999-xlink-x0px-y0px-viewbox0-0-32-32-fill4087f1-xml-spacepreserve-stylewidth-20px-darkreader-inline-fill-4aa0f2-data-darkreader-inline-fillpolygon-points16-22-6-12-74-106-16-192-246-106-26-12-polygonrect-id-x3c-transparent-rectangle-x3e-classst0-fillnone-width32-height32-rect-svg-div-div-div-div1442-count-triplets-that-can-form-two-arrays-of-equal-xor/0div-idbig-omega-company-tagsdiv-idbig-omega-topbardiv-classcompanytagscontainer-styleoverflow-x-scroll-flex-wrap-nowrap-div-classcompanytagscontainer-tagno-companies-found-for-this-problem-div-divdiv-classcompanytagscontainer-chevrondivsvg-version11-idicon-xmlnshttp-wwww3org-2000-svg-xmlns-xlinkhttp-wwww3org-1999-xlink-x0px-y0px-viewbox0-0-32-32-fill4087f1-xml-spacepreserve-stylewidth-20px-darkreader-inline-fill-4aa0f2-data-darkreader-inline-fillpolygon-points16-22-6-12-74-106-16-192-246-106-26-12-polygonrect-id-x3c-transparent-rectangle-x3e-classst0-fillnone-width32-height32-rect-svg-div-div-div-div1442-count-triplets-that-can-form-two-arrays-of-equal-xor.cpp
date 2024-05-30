class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> pref(n);
        
        int x = 0;
        for(int i = 0; i < n; i++)
        {
            x ^= arr[i];
            pref[i] = x;
        }
        
        int ans = 0;
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(pref[i] == pref[j])
                    ans += (j - i - 1);
                else if(i == 0 && pref[j] == 0)
                    ans += j;
            }
        }
        
        return ans;
    }
};