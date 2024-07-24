class Solution {
public:
    int maxVowels(string s, int k) {
        
        int n = s.size();
        int v = 0;
        int ans = 0;
        int i = 0, j = 0;

        while(j < n)
        {
            if(j - i + 1 < k)
            {
                if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                    v++;

                j++;
            }
            else if(j - i + 1 == k)
            {
                if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                    v++;
                
                j++;
            }
            else
            {
                if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                    v++;
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                    v--;
                i++;
                j++;
            }

            ans = max(ans, v);
        }

        return ans;
    }
};