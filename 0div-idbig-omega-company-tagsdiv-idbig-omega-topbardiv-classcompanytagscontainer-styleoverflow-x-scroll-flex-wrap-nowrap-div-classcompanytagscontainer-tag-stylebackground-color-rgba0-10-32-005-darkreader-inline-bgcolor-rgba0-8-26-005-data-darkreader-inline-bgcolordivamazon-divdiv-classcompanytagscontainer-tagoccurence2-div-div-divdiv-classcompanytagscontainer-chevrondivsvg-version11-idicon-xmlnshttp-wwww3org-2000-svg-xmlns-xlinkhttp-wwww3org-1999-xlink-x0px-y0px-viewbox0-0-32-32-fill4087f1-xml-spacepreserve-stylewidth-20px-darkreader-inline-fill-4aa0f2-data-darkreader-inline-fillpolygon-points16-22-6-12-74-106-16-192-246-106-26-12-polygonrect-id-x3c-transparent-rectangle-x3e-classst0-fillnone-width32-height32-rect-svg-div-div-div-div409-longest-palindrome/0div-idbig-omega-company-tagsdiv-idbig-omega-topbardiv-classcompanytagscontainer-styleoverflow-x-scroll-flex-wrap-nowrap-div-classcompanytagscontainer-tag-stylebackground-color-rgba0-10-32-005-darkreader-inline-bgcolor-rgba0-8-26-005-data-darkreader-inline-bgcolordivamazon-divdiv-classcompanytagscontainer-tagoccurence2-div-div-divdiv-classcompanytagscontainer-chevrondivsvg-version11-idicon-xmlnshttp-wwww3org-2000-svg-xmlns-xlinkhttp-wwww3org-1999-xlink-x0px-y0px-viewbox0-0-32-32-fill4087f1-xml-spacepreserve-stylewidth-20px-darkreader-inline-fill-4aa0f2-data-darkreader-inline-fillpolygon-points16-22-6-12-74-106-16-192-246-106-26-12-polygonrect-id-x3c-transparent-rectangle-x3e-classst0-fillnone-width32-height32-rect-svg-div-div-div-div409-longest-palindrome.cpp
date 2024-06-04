class Solution {
public:
    int longestPalindrome(string s) {
        
        vector<int> hash(60, 0);
        for(auto it : s)
            hash[it - 'A']++;
        
        int cnt = 0, odd = 0, z = 0;
        for(int i = 0; i < 60; i++)
        {
            if(hash[i] % 2 == 0)
                cnt += hash[i];
            else
            {
                z = 1;
                odd += hash[i] - 1;
            }
        }
        
        if(z == 0)
            return cnt;
        
        return cnt + odd + 1;
    }
};